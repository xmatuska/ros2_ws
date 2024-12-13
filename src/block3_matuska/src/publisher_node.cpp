#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>

class STLVisualizationNode : public rclcpp::Node
{
public:
  STLVisualizationNode()
      : Node("stl_visualization_node")
  {
    // Create a publisher for Marker messages
    marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/visualization_marker", 10);

    // Timer to periodically publish the marker
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&STLVisualizationNode::publishMarker, this));
  }

private:
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  void publishMarker()
  {
    // Create a marker message
    visualization_msgs::msg::Marker marker;

    marker.header.frame_id = "base_link"; // Reference frame for the marker
    marker.header.stamp = this->now();   // Timestamp
    marker.ns = "meshes";                // Namespace for the marker
    marker.id = 0;                       // Unique ID for this marker
    marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE; // Mesh resource type
    marker.action = visualization_msgs::msg::Marker::ADD;         

    // Pose (position and orientation)
    marker.pose.position.x = 1.6;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.3;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.258819;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 0.9659258;

    // Scale
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    // Color
    marker.color.r = 0.5;
    marker.color.g = 0.5;
    marker.color.b = 0.5;
    marker.color.a = 1.0;

    // Mesh resource path
    marker.mesh_resource = "file:///home/matus/ros2_ws/src/block3_matuska/src/tie.stl";

    // Publish the marker
    marker_pub_->publish(marker);

    RCLCPP_INFO(this->get_logger(), "Published STL Marker");
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<STLVisualizationNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
