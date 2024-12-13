cmake_minimum_required(VERSION 3.8)
project(block2_matuska)


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_srvs REQUIRED)  
find_package(Eigen3 REQUIRED)
find_package(abb_irb4600_ikfast REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
)


add_executable(zadanie2_node src/zadanie2_node.cpp)
add_executable(zadanie22_node src/zadanie22_node.cpp)


ament_target_dependencies(
  zadanie2_node
  rclcpp
  sensor_msgs
  std_srvs  
)

ament_target_dependencies(
  zadanie22_node
  rclcpp
  sensor_msgs
  std_srvs  
  abb_irb4600_ikfast
)


install(TARGETS zadanie2_node zadanie22_node
  DESTINATION lib/${PROJECT_NAME})
  

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
