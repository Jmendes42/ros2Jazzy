cmake_minimum_required(VERSION 3.22.1)
project(jazzy)

add_subdirectory(ws/src/ros2_fundamentals_examples)

add_subdirectory(ws/src/mycobot/mycobot)
add_subdirectory(ws/src/mycobot/mycobot_bringup)
add_subdirectory(ws/src/mycobot/mycobot_description)
add_subdirectory(ws/src/mycobot/mycobot_gazebo)
add_subdirectory(ws/src/mycobot/mycobot_moveit_config)
add_subdirectory(ws/src/mycobot/mycobot_system_tests)

add_subdirectory(ws/src/yahboom_rosmaster/yahboom_rosmaster)
add_subdirectory(ws/src/yahboom_rosmaster/yahboom_rosmaster_description)

set(CMAKE_CXX_STANDARD 20)