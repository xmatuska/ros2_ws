#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/msg/command.hpp"
#include "rrm_msgs/srv/command.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Teleop : public rclcpp::Node
{
public:
    Teleop() : Node("Teleop")
    {
        client_ = this->create_client<rrm_msgs::srv::Command>("move_command");

        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
        }

        //inicializacia prvotnych pozicii
        last_positions_ = {0.0, 0.0, 0.0};

        RCLCPP_INFO(this->get_logger(), "Teleop initialized");
    }

    bool move(const std::vector<double>& positions, double max_velocity) {
        std::vector<double> current_positions = last_positions_; // aktualizuje aktualnu poziciu
        std::vector<double> velocities = calculateVelocities(current_positions, positions, max_velocity);

        auto request = std::make_shared<rrm_msgs::srv::Command::Request>();
        request->positions = positions;
        request->velocities = velocities;

        auto result = client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "Request called");

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) !=
            rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
            return false;
        }

        auto response = result.get();
        RCLCPP_INFO(this->get_logger(), "Service call succeeded: result_code = %d, message = %s",
                    response->result_code, response->message.c_str());

        if (!response->result_code) {
            last_positions_ = positions;
        }

        return !response->result_code;
    }

private:
    rclcpp::Client<rrm_msgs::srv::Command>::SharedPtr client_;
    std::vector<double> last_positions_; // posledne pozicie klbov

    std::vector<double> calculateVelocities(const std::vector<double>& current_positions,
                                             const std::vector<double>& target_positions,
                                             double max_velocity) {
        std::vector<double> velocities(current_positions.size());
        double max_time;

        // vypocet max casu na dosiahnutie cielovej pozicie
        for (size_t i = 0; i < current_positions.size(); ++i) {
            double distance = std::abs(target_positions[i] - current_positions[i]);
            double time = distance / max_velocity;
            max_time = std::max(max_time, time);
        }

        // vypocet rychlosti pre kazdy klb
        for (size_t i = 0; i < current_positions.size(); ++i) {
            double distance = target_positions[i] - current_positions[i];
            velocities[i] = distance / max_time; //vypocet

            // kontrola max rychlosti
            if (std::abs(velocities[i]) > max_velocity) {
                velocities[i] = (velocities[i] > 0) ? max_velocity : -max_velocity;
            }
        }

        return velocities;
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    Teleop robot;
    
    sleep(5);
    robot.move({1.0, 2.0, 3.0}, 0.5);
    //sleep(1);
    //robot.move({2.0, 1.0, 2.0}, 0.5);
    //sleep(1);
    //robot.move({0.0, 0.0, 0.0}, 0.5);
    rclcpp::shutdown();
    return 0;
}
