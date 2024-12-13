#include "rclcpp/rclcpp.hpp"
#include "logger_node.hpp"
#include "matuska_interface/srv/teach_position.hpp"
#include <Eigen/Geometry>
#include <tf2_ros/transform_broadcaster.h>
#include <sensor_msgs/msg/joint_state.hpp>

#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

JointLogger::JointLogger() : Node("joint_logger"), tf_broadcaster_(this)
{
    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));

    service_ = this->create_service<matuska_interface::srv::TeachPosition>("TeachPosition",
        std::bind(&JointLogger::teach_position_callback, this, std::placeholders::_1, std::placeholders::_2));
}

void JointLogger::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    current_joint_positions.clear();
    for (const auto& pos : msg->position) {
        current_joint_positions.push_back(pos);
    }

    RCLCPP_INFO(this->get_logger(), "Joint states updated");

    Eigen::Matrix4d T = Eigen::Matrix4d::Identity();

    // Loop through each joint to calculate the full transformation matrix
    for (size_t i = 0; i < current_joint_positions.size(); ++i) {
        double theta = (i != 5) ? current_joint_positions[i] : 0.0;  // Theta is zero for prismatic joint
        double d, a, alpha;

        // Assign DH parameters per joint index
        switch (i) {
            case 0: d = 0; a = 0; alpha = 0; break;
            case 1: d = 0; a = 0; alpha = 0; break;
            case 2: d = 0.178; a = 0; alpha = 0; break;
            case 3: d = 0.203; a = 0; alpha = 0; break;
            case 4: d = 0.203; a = 0; alpha = 0; break;
            case 5: d = 0.05 + current_joint_positions[i]; a = 0; alpha = 0; break;
        }

        // Create the transformation matrix for the current joint
        Eigen::Matrix4d T_i;
        T_i << cos(theta), -sin(theta) * cos(alpha), sin(theta) * sin(alpha), a * cos(theta),
               sin(theta), cos(theta) * cos(alpha), -cos(theta) * sin(alpha), a * sin(theta),
               0, sin(alpha), cos(alpha), d,
               0, 0, 0, 1;

        // Update the overall transformation matrix
        T *= T_i;
    }

    // Add the fixed transform for the tool
    Eigen::Matrix4d T_tool0 = Eigen::Matrix4d::Identity();
    T_tool0(2, 3) = 0.15;
    T *= T_tool0;

    // Log the final transformation matrix
    RCLCPP_INFO(this->get_logger(), "Calculated Transformation Matrix T:");
    RCLCPP_INFO(this->get_logger(), "[%.2f, %.2f, %.2f, %.2f]", T(0, 0), T(0, 1), T(0, 2), T(0, 3));
    RCLCPP_INFO(this->get_logger(), "[%.2f, %.2f, %.2f, %.2f]", T(1, 0), T(1, 1), T(1, 2), T(1, 3));
    RCLCPP_INFO(this->get_logger(), "[%.2f, %.2f, %.2f, %.2f]", T(2, 0), T(2, 1), T(2, 2), T(2, 3));
    RCLCPP_INFO(this->get_logger(), "[%.2f, %.2f, %.2f, %.2f]", T(3, 0), T(3, 1), T(3, 2), T(3, 3));

    // Extract translation and rotation from T matrix for broadcasting
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = this->get_clock()->now();
    transform.header.frame_id = "base_link";
    transform.child_frame_id = "tool0_calculated";

    transform.transform.translation.x = T(0, 3);
    transform.transform.translation.y = T(1, 3);
    transform.transform.translation.z = T(2, 3);
    Eigen::Quaterniond q(T.block<3, 3>(0, 0));
    transform.transform.rotation.x = q.x();
    transform.transform.rotation.y = q.y();
    transform.transform.rotation.z = q.z();
    transform.transform.rotation.w = q.w();

    tf_broadcaster_.sendTransform(transform);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void JointLogger::save_position_to_file(int id, const std::vector<double>& joint_positions, float max_speed) {
    std::ofstream file("trajectory_points.txt", std::ios::app);
    if (file.is_open()) {
        file << id << " ";
        for (const auto& pos : joint_positions) {
            file << pos << " ";
        }
        file << max_speed << "\n";
        file.close();
    } else {
        RCLCPP_ERROR(this->get_logger(), "Unable to open file for writing");
    }
}

void JointLogger::teach_position_callback(const std::shared_ptr<matuska_interface::srv::TeachPosition::Request> request, 
                                          std::shared_ptr<matuska_interface::srv::TeachPosition::Response> response)
{
    int id = point_id_counter_++;  // id bodu
    float max_speed = request->velocity;

    if (current_joint_positions.empty()) {
        RCLCPP_WARN(this->get_logger(), "pozicie nie su dostupne");
        response->result = false;
        response->message = "pozicie nie su dostupne";
        return;
    }

    save_position_to_file(id, current_joint_positions, max_speed);

    RCLCPP_INFO(this->get_logger(), "pozicia ulozena: ID=%d, rychlost:=%f", id, max_speed);
    response->result = true;
    response->message = "pozicia ulozena";
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    std::shared_ptr<JointLogger> logger = std::make_shared<JointLogger>();
    rclcpp::spin(logger);
    rclcpp::shutdown();
    return 0;
}
