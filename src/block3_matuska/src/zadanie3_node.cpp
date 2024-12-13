#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

static const rclcpp::Logger LOGGER = rclcpp::get_logger("move_group_demo");

int main(int argc, char** argv){

  rclcpp::init(argc, argv);
  rclcpp::NodeOptions node_options;
  node_options.automatically_declare_parameters_from_overrides(true);
  auto move_group_node = rclcpp::Node::make_shared("move_group_interface_tutorial", node_options);

  // We spin up a SingleThreadedExecutor for the current state monitor to get information about the robot's state.
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(move_group_node);
  std::thread([&executor]() { executor.spin(); }).detach();

  // Setup
  // ^^^^^
  static const std::string PLANNING_GROUP = "abb_group";
  moveit::planning_interface::MoveGroupInterface move_group(move_group_node, PLANNING_GROUP);
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // Raw pointers are frequently used to refer to the planning group for improved performance.
  const moveit::core::JointModelGroup* joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  // Set the reference frame for pose targets
  move_group.setPoseReferenceFrame("world");

  // We can print the name of the reference frame for this robot.
  RCLCPP_INFO(LOGGER, "Planning frame: %s", move_group.getPlanningFrame().c_str());

  move_group.setEndEffectorLink("kinect_mesh");

  // We can also print the name of the end-effector link for this group.
  //RCLCPP_INFO(LOGGER, "End effector link: %s", move_group.getEndEffectorLink().c_str());

  std::vector<std::string> link_names = move_group.getLinkNames();
  RCLCPP_INFO(LOGGER, "Link names in the robot model:");
  for (const auto& link_name : link_names) {
    RCLCPP_INFO(LOGGER, "  %s", link_name.c_str());
  }

  // Sleep
  RCLCPP_INFO(LOGGER, "Sleeping for 3 seconds");
  rclcpp::sleep_for(std::chrono::seconds(3));

  // Joint Space Goal
  // ^^^^^^^^^^^^^^^^

  // Set start state to current state
  move_group.setStartStateToCurrentState();

  std::vector<double> current_joint_values = move_group.getCurrentJointValues();

  // Vypísanie aktuálnych hodnôt kĺbov
  RCLCPP_INFO(LOGGER, "Aktuálne hodnoty kĺbov:");
  for (size_t i = 0; i < current_joint_values.size(); ++i) {
      RCLCPP_INFO(LOGGER, "Kĺb %zu: %f rad", i, current_joint_values[i]);
  }

  // prvy klbovy
  std::vector<double> joint_group_positions = {-0.83, 0.31, -0.45, 3.54, -0.85, -4.60};

  bool within_bounds = move_group.setJointValueTarget(joint_group_positions);
  if (!within_bounds)
  {
    RCLCPP_ERROR(LOGGER, "Target joint position(s) were outside of limits");
    rclcpp::shutdown();
  }

  move_group.setMaxVelocityScalingFactor(0.2);
  move_group.setMaxAccelerationScalingFactor(0.2);

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (move_group.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
  RCLCPP_INFO(LOGGER, "Visualizing joint space goal %s", success ? "" : "FAILED");
  move_group.execute(my_plan.trajectory); 

  // Sleep
  RCLCPP_INFO(LOGGER, "Sleeping for 3 seconds");
  rclcpp::sleep_for(std::chrono::seconds(3));

  // Cartesian Paths
  // ^^^^^^^^^^^^^^^
  // You can plan a Cartesian path directly by specifying a list of waypoints for the end-effector to go through.

  geometry_msgs::msg::Pose start_pose = move_group.getCurrentPose().pose;

  std::vector<geometry_msgs::msg::Pose> waypoints;
  waypoints.push_back(start_pose);

  geometry_msgs::msg::Pose target_pose = start_pose;

  target_pose.position.x = 1.44;
  target_pose.position.y = -1.27;
  target_pose.position.z = 1.23;
  waypoints.push_back(target_pose);  // k poz1

  target_pose.position.x = 1.10;
  target_pose.position.y = -0.97;
  target_pose.position.z = 0.67;
  waypoints.push_back(target_pose);  // k poz2

  target_pose.position.x = 1.33;
  target_pose.position.y = -0.7;
  target_pose.position.z = 1.05;
  waypoints.push_back(target_pose);  // k poz3

  target_pose.position.x = 1.11;
  target_pose.position.y = -0.69;
  target_pose.position.z = 1.17; 
  waypoints.push_back(target_pose);  //zodvihni
  
  // planovanie kartezkeho 1
  const double eef_step = 0.01;
  const double jump_threshold = 0.0;  
  moveit_msgs::msg::RobotTrajectory trajectory;
  double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
  RCLCPP_INFO(LOGGER, "Visualizing Cartesian path (%.2f%% achieved)", fraction * 100.0);

  move_group.execute(trajectory);

  // z kartezkeho klbovym nad ziadany bod
  std::vector<double> joint_group_positions_target = {-0.82, -0.19, 0.767, 3.54, -0.21, -4.6}; 
  move_group.setJointValueTarget(joint_group_positions_target);
  success = (move_group.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
  RCLCPP_INFO(LOGGER, "Planning to joint position %s", success ? "" : "FAILED");
  move_group.execute(my_plan.trajectory);

  // definicia dalsieho kartezkeho posunu

  geometry_msgs::msg::Pose additional_start_pose = move_group.getCurrentPose().pose;

  std::vector<geometry_msgs::msg::Pose> additional_waypoints;
  additional_waypoints.push_back(additional_start_pose);

  geometry_msgs::msg::Pose additional_target_pose = additional_start_pose;

  // kartezke posuny
  additional_target_pose.position.x = 1.10;
  additional_target_pose.position.y = -0.97;
  additional_target_pose.position.z = 0.67;
  additional_waypoints.push_back(additional_target_pose);

  additional_target_pose.position.x = 1.12;
  additional_target_pose.position.y = -0.26;
  additional_target_pose.position.z = 0.67;
  additional_waypoints.push_back(additional_target_pose);

  additional_target_pose.position.x = 0.99;
  additional_target_pose.position.y = -0.28;
  additional_target_pose.position.z = 0.74;
  additional_waypoints.push_back(additional_target_pose);

  // planovanie kartezkeho 2
  const double additional_eef_step = 0.01;
  const double additional_jump_threshold = 0.0;
  moveit_msgs::msg::RobotTrajectory additional_trajectory;
  double additional_fraction = move_group.computeCartesianPath(additional_waypoints, additional_eef_step, additional_jump_threshold, additional_trajectory);
  RCLCPP_INFO(LOGGER, "Visualizing additional Cartesian path (%.2f%% achieved)", additional_fraction * 100.0);

  // spustenie kartezkeho
  move_group.execute(additional_trajectory);

  //vratenie sa klbovym domov
  std::vector<double> joint_group_positions_target2 = {0, 0, 0, 0, 0, 0};  // joint target
  move_group.setJointValueTarget(joint_group_positions_target2);
  success = (move_group.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
  RCLCPP_INFO(LOGGER, "Planning to joint position %s", success ? "" : "FAILED");
  move_group.execute(my_plan.trajectory);

  //ende
  rclcpp::shutdown();
  return 0;
}