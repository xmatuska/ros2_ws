#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "matuska_interface/srv/teach_position.hpp"
#include <tf2_ros/transform_broadcaster.h>


class JointLogger : public rclcpp::Node
{

public:
        JointLogger();
        void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
        void teach_position_callback(const std::shared_ptr<matuska_interface::srv::TeachPosition::Request> request,
                                        std::shared_ptr<matuska_interface::srv::TeachPosition::Response> response);
        void save_position_to_file(int id, const std::vector<double>& joint_positions, float max_speed);
        
    private:
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
        rclcpp::Service<matuska_interface::srv::TeachPosition>::SharedPtr service_;
        tf2_ros::TransformBroadcaster tf_broadcaster_;
        int point_id_counter_ = 0; 
        std::vector<double> current_joint_positions; // vektor na konkretne pozicie
        
};
