cmake_minimum_required(VERSION 3.8)
project(ros2_fundamentals_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(minimal_publisher src/MinimalPublisher.cpp)
ament_target_dependencies(minimal_publisher rclcpp std_msgs)

add_executable(minimal_subscriber src/MinimalSubscriber.cpp)
ament_target_dependencies(minimal_subscriber rclcpp std_msgs)

install(TARGETS
    minimal_publisher
    minimal_subscriber
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(publisher_test test/test_publisher.cpp)
  ament_target_dependencies(publisher_test rclcpp std_msgs ${dependencies})

  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
endif()

ament_package()
