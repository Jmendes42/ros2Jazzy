
#ifndef __JAZZY_MINIMAL_SUBSCRIBER_H__
#define __JAZZY_MINIMAL_SUBSCRIBER_H__

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/string.hpp>


class MinimalSubscriber : public rclcpp::Node
{
public:
    MinimalSubscriber();

private:
    void callback(std_msgs::msg::String::SharedPtr const message);

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
};

#endif