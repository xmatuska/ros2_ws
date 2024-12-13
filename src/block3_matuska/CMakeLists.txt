cmake_minimum_required(VERSION 3.8)
project(block3_matuska)

# Enable warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)  # Include visualization_msgs for Marker support
find_package(geometric_shapes REQUIRED)   # Include geometric_shapes for working with STL files
find_package(shape_msgs REQUIRED)         # Include shape_msgs for mesh support

# Add executable for zadanie3_node
add_executable(zadanie3_node src/zadanie3_node.cpp)
target_include_directories(zadanie3_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(zadanie3_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  zadanie3_node
  "rclcpp"
  "moveit_core"
  "moveit_ros_planning_interface"
  "rclcpp_action"
  "geometry_msgs"
  "moveit_msgs"
)

# Add executable for publisher_node
add_executable(publisher_node src/publisher_node.cpp)
target_include_directories(publisher_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(publisher_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  publisher_node
  "rclcpp"
  "geometry_msgs"
  "visualization_msgs"  # Ensure visualization_msgs is linked
  "geometric_shapes"    # Add dependency on geometric_shapes
  "shape_msgs"          # Add dependency on shape_msgs (for mesh)
)

# Install executables
install(TARGETS
  zadanie3_node
  publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

# Testing and linting
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE) # Skip copyright checks
  set(ament_cmake_cpplint_FOUND TRUE)   # Skip cpplint checks
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

