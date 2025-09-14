cmake_minimum_required(VERSION 3.8)
project(mycobot_system_tests)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(control_msgs REQUIRED)

add_executable(arm_gripper_controller src/arm_gripper_controller.cpp)
ament_target_dependencies(arm_gripper_controller rclcpp rclcpp_action control_msgs)

install(
    TARGETS
    arm_gripper_controller
    DESTINATION lib/${PROJECT_NAME}
)

install(
    DIRECTORY scripts src
    DESTINATION share/${PROJECT_NAME}
)

install(
    PROGRAMS scripts/arm_gripper_loop_controller.py
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
