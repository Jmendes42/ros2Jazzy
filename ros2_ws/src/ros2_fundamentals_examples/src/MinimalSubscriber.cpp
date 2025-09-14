
#include "MinimalSubscriber.h"

MinimalSubscriber::MinimalSubscriber()
    : Node("minimal_subscriber")
{
    _subscription = create_subscription<std_msgs::msg::String>("minimal_topic", 10,
        [this](std_msgs::msg::String::SharedPtr const message) { callback(message); });
}

void MinimalSubscriber::callback(std_msgs::msg::String::SharedPtr const message)
{
    RCLCPP_INFO(get_logger(), "I received the message: %s", message->data.c_str());
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
