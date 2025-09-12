cmake_minimum_required(VERSION 3.22.1)
project(jazzy)

add_subdirectory(ws/src/ros2_fundamentals_examples)
add_subdirectory(ws/src/mycobot/mycobot)
add_subdirectory(ws/src/mycobot/mycobot_description)

set(CMAKE_CXX_STANDARD 20)