
#include "MinimalPublisher.h"


MinimalPublisher::MinimalPublisher()
    : Node("minimal_publisher")
    , _count(0)
{
    _publisher = create_publisher<std_msgs::msg::String>("minimal_publisher", 10);
    _timer = create_wall_timer(std::chrono::milliseconds(500), [this] { timerCallback(); });
    RCLCPP_INFO(get_logger(), "MinimalPublisher created");
}

void MinimalPublisher::timerCallback()
{
    auto message = std_msgs::msg::String();
    message.data = "Hello World! " + std::to_string(_count++);
    _publisher->publish(message);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
