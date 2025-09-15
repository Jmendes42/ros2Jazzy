cmake_minimum_required(VERSION 3.8)
project(yahboom_rosmaster_system_tests)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)

add_executable(mecanum_parameters src/mecanum_parameters_node.cpp)
ament_target_dependencies(mecanum_parameters rclcpp geometry_msgs std_msgs rcl_interfaces)

add_executable(square_mecanum_controller src/square_mecanum_controller.cpp)
ament_target_dependencies(square_mecanum_controller rclcpp geometry_msgs std_msgs)

install(TARGETS
    mecanum_parameters
    square_mecanum_controller
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
