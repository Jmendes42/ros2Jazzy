

#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MinimalPublisher;

#define TESTING_EXCLUDE_MAIN
#include "../src/MinimalPublisher.cpp"

class TestMinimalPublisher : public ::testing::Test
{
protected:
    void SetUp() override
    {
        rclcpp::init(0, nullptr);
        node = std::make_shared<MinimalPublisher>();
    }
    void TearDown() override
    {
        node.reset();
        rclcpp::shutdown();
    }
    std::shared_ptr<MinimalPublisher> node;
};

TEST_F(TestMinimalPublisher, TestNodeCreation)
{
    EXPECT_EQ(std::string(node->get_name()), "minimal_publisher");

    auto const publisherEndpoints = node->get_publishers_info_by_topic("minimal_topic");
    EXPECT_EQ(publisherEndpoints.size(), 1);
}

TEST_F(TestMinimalPublisher, TestMessageContent)
{
    std::shared_ptr<std_msgs::msg::String> receivedMessage;

    auto const subscription = node->create_subscription<std_msgs::msg::String>(
        "minimal_topic", 10,
        [&receivedMessage](std_msgs::msg::String::SharedPtr const message)
        {
            receivedMessage = std::make_shared<std_msgs::msg::String>(*message);
        });
    node->timerCallback();
    rclcpp::spin_some(node);

    EXPECT_EQ(receivedMessage->data.substr(0, 12), "Hello World!");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
