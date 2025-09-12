
#ifndef __JAZZY_MINIMAL_PUBLISHER_H__
#define __JAZZY_MINIMAL_PUBLISHER_H__

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher();

    void timerCallback();
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;
    rclcpp::TimerBase::SharedPtr _timer;
    int _count;
};


#endif