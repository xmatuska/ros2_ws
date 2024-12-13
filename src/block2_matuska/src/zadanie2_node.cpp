#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_srvs/srv/trigger.hpp>  // ROS2 defaultna service
#include <Eigen/Geometry>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath> 

Eigen::MatrixXd Matica(double t0, double tf) {
    Eigen::MatrixXd m(6, 6);
    m <<    1, t0, pow(t0, 2), pow(t0, 3), pow(t0, 4), pow(t0, 5),
            0, 1, 2 * t0, 3 * pow(t0, 2), 4 * pow(t0, 3), 5 * pow(t0, 4),
            0, 0, 2, 6 * t0, 12 * pow(t0, 2), 20 * pow(t0, 3),
            1, tf, pow(tf, 2), pow(tf, 3), pow(tf, 4), pow(tf, 5),
            0, 1, 2 * tf, 3 * pow(tf, 2), 4 * pow(tf, 3), 5 * pow(tf, 4),
            0, 0, 2, 6 * tf, 12 * pow(tf, 2), 20 * pow(tf, 3);

    return m;
}

class TrajectoryNode : public rclcpp::Node {
public:
    TrajectoryNode() : Node("zadanie2_node"), service_called_(false), csv_file_("trajectory_log.csv") {
        // publisher na joint states
        publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

        // vizualizacia sa zapne ked spustim trigger "zapni_robota"
        service_ = this->create_service<std_srvs::srv::Trigger>(
            "zapni_robota",
            std::bind(&TrajectoryNode::startTrajectoryCallback, this, std::placeholders::_1, std::placeholders::_2)
        );

        // Set joint names
        joint_names_ = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
        RCLCPP_INFO(this->get_logger(), "Service 'start_trajectory' is ready.");

        // Initialize joint state message
        joint_state_.name = joint_names_;
        joint_state_.position.resize(joint_names_.size(), 0.0);
        joint_state_.velocity.resize(joint_names_.size(), 0.0);
        joint_state_.effort.resize(joint_names_.size(), 0.0);


        csv_file_ << "time,position_1,velocity_1,acceleration_1,jerk_1,position_2,velocity_2,acceleration_2,jerk_2\n";

        // setnutie robota do defaultnej pozicie
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&TrajectoryNode::publishDefaultPosition, this)
        );
    }

    ~TrajectoryNode() {
        if (csv_file_.is_open()) {
            csv_file_.close();
        }
    }

private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::vector<std::string> joint_names_;
    sensor_msgs::msg::JointState joint_state_;
    bool service_called_;
    std::ofstream csv_file_;

    void publishDefaultPosition() {
        // setnutie do defaultnej pozicie ak neni spustena service
        if (!service_called_) {
            joint_state_.header.stamp = this->get_clock()->now();
            publisher_->publish(joint_state_);
        }
    }

    void startTrajectoryCallback(
        const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
        std::shared_ptr<std_srvs::srv::Trigger::Response> response
    ) {
        RCLCPP_INFO(this->get_logger(), "Service called. Starting trajectory calculation...");

        service_called_ = true;
        timer_->cancel();

        Eigen::MatrixXd klb1m = Matica(0, 4);
        Eigen::MatrixXd klb3m1 = Matica(0, 1);
        Eigen::MatrixXd klb3m2 = Matica(1, 4);

        Eigen::VectorXd q1(6); 
        q1 << 0, 0, 0, M_PI / 2, 0, 0;

        Eigen::VectorXd q31(6); 
        q31 << 0, 0, 0, M_PI / 6, 0, 0;

        Eigen::VectorXd q32(6); 
        q32 << M_PI / 6, 0, 0, 0, 0, 0;

        Eigen::VectorXd a1 = klb1m.inverse() * q1;
        Eigen::VectorXd a31 = klb3m1.inverse() * q31;
        Eigen::VectorXd a32 = klb3m2.inverse() * q32;

        int frequency = 100;  // Hz
        double max_time = 4.0;  // s
        rclcpp::Rate loop_rate(frequency);

        while (rclcpp::ok()) {
            for (double t = 0; t <= max_time; t += 0.01) {

                std::vector<double> hodnoty1 = hodnoty(t, a1);
                double jerk_1 = 0;
                
                joint_state_.position[0] = hodnoty1[0];
                joint_state_.velocity[0] = hodnoty1[1];
                joint_state_.effort[0] = hodnoty1[2];
                jerk_1 = hodnoty1[3];

                double position_2 = 0, velocity_2 = 0, acceleration_2 = 0, jerk_2 = 0;

                if (t <= 1) {
                    std::vector<double> hodnoty2 = hodnoty(t, a31);
                    position_2 = hodnoty2[0];
                    velocity_2 = hodnoty2[1];
                    acceleration_2 = hodnoty2[2];
                    jerk_2 = hodnoty2[3];
                } else {
                    std::vector<double> hodnoty3 = hodnoty(t, a32);
                    position_2 = hodnoty3[0];
                    velocity_2 = hodnoty3[1];
                    acceleration_2 = hodnoty3[2];
                    jerk_2 = hodnoty3[3];
                }

                joint_state_.position[2] = position_2;
                joint_state_.velocity[2] = velocity_2;
                joint_state_.effort[2] = acceleration_2;
               

                // logovanie
                csv_file_ << t << "," 
                          << joint_state_.position[0] << "," << joint_state_.velocity[0] << "," << joint_state_.effort[0] << "," << jerk_1 << ","
                          << position_2 << "," << velocity_2 << "," << acceleration_2 << "," << jerk_2 <<  "\n";

                joint_state_.header.stamp = this->get_clock()->now();
                publisher_->publish(joint_state_);
                loop_rate.sleep();
            }

            response->success = true;
            response->message = "Trajectory executed successfully!";
            RCLCPP_INFO(this->get_logger(), "Trajectory execution completed.");
        }
    }

    std::vector<double> hodnoty(double t, const Eigen::VectorXd &a) {
        double pozicia = a[0] + a[1] * t + a[2] * pow(t, 2) + a[3] * pow(t, 3) + a[4] * pow(t, 4) + a[5] * pow(t, 5);
        double rychlost = a[1] + 2 * a[2] * t + 3 * a[3] * pow(t, 2) + 4 * a[4] * pow(t, 3) + 5 * a[5] * pow(t, 4);
        double zrychlenie = 2 * a[2] + 6 * a[3] * t + 12 * a[4] * pow(t, 2) + 20 * a[5] * pow(t, 3);
        double trh = 6 * a[3] + 24 * a[4] * t + 60 * a[5] * pow(t, 2);

        return {pozicia, rychlost, zrychlenie, trh};
    }
};

//ros2 service call /zapni_robota std_srvs/srv/Trigger

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
