#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <Eigen/Dense>
#include <vector>
#include <fstream>

class TrajectoryVisualization : public rclcpp::Node {
public:
    TrajectoryVisualization() : Node("trajectory_visualization"), trajectory_active_(true) {
        // Inicializácia publikátora pre joint_states
        publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

        // Definovanie počiatočných a koncových podmienok pre Q1
        T_ = 4.0;
        Q0_1 = 0.0;
        Qf_1 = 90.0;
        dQ0_1 = 0.0;
        dQf_1 = 0.0;

        // Definovanie počiatočných, medzičasových a koncových podmienok pre Q3
        Q0_3 = 0.0;
        Qm_3 = 30.0; // Medzičasová pozícia v čase t = 1
        Qf_3 = 0.0;
        dQ0_3 = 0.0;
        dQf_3 = 0.0;

        // Výpočet koeficientov pre trajektórie
        computeCoefficients(Q0_1, Qf_1, dQ0_1, dQf_1, T_, coeffs_1);
        computePiecewiseCoefficients(Q0_3, Qm_3, Qf_3, dQ0_3, dQf_3, 1.0, 4.0, coeffs_3_start, coeffs_3_end);

        // Nastavenie mena kĺbov pre joint state správu
        joint_state_.name = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
        joint_state_.position.resize(6, 0.0);

        // Otvorenie CSV súboru pre zápis
        csv_file_.open("trajectory_log.csv", std::ios::out);
        csv_file_ << "time,Q1_position,Q1_velocity,Q1_acceleration,Q3_position,Q3_velocity,Q3_acceleration\n";

        // Nastavenie frekvencie publikovania trajektórie
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10), std::bind(&TrajectoryVisualization::publishTrajectory, this)
        );

        // Počiatočný čas spustenia
        start_time_ = this->get_clock()->now().seconds();
    }

    ~TrajectoryVisualization() {
        if (csv_file_.is_open()) {
            csv_file_.close();
        }
    }

private:
    void computeCoefficients(double Q0, double Qf, double dQ0, double dQf, double T, Eigen::Vector4d &coeffs) {
        Eigen::Matrix4d A;
        A << 1, 0, 0, 0,
             0, 1, 0, 0,
             1, T, T * T, T * T * T,
             0, 1, 2 * T, 3 * T * T;

        Eigen::Vector4d b;
        b << Q0, dQ0, Qf, dQf;

        coeffs = A.colPivHouseholderQr().solve(b);
    }

    void computePiecewiseCoefficients(double Q0, double Qm, double Qf, double dQ0, double dQf, double T1, double T2, Eigen::Vector4d &coeffs_start, Eigen::Vector4d &coeffs_end) {
        // Výpočet koeficientov pre prvý interval (0 až T1)
        computeCoefficients(Q0, Qm, dQ0, 0.0, T1, coeffs_start);

        // Výpočet koeficientov pre druhý interval (T1 až T2)
        computeCoefficients(Qm, Qf, 0.0, dQf, T2 - T1, coeffs_end);
    }

    double evaluatePosition(const Eigen::Vector4d &coeffs, double t) {
        return coeffs(0) + coeffs(1) * t + coeffs(2) * t * t + coeffs(3) * t * t * t;
    }

    double evaluateVelocity(const Eigen::Vector4d &coeffs, double t) {
        return coeffs(1) + 2 * coeffs(2) * t + 3 * coeffs(3) * t * t;
    }

    double evaluateAcceleration(const Eigen::Vector4d &coeffs, double t) {
        return 2 * coeffs(2) + 6 * coeffs(3) * t;
    }

    void publishTrajectory() {
        if (!trajectory_active_) return;

        double t = this->get_clock()->now().seconds() - start_time_;
        if (t > T_) {
            trajectory_active_ = false;
            t = T_;
        }

        // Vypočítať hodnoty pre kĺb 1
        double q1_pos = evaluatePosition(coeffs_1, t);
        double q1_vel = evaluateVelocity(coeffs_1, t);
        double q1_acc = evaluateAcceleration(coeffs_1, t);

        // Vypočítať hodnoty pre kĺb 3 s dvoma intervalmi
        Eigen::Vector4d current_coeffs_3 = (t <= 1.0) ? coeffs_3_start : coeffs_3_end;
        double t_interval = (t <= 1.0) ? t : t - 1.0;
        double q3_pos = evaluatePosition(current_coeffs_3, t_interval);
        double q3_vel = evaluateVelocity(current_coeffs_3, t_interval);
        double q3_acc = evaluateAcceleration(current_coeffs_3, t_interval);

        joint_state_.position[0] = q1_pos;
        joint_state_.position[2] = q3_pos;

        joint_state_.header.stamp = this->get_clock()->now();
        publisher_->publish(joint_state_);

        if (csv_file_.is_open()) {
            csv_file_ << t << "," << q1_pos << "," << q1_vel << "," << q1_acc << ","
                      << q3_pos << "," << q3_vel << "," << q3_acc << "\n";
        }
    }

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    sensor_msgs::msg::JointState joint_state_;

    Eigen::Vector4d coeffs_1, coeffs_3_start, coeffs_3_end;
    double T_, Q0_1, Qf_1, dQ0_1, dQf_1;
    double Q0_3, Qm_3, Qf_3, dQ0_3, dQf_3;
    double start_time_;
    bool trajectory_active_;

    std::ofstream csv_file_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryVisualization>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
