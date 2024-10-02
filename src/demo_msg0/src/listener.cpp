#include <ros/ros.h>
#include <std_msgs/String.h>

void Msg_callback(const std_msgs::String::ConstPtr& msg_p)
{
    ROS_INFO("我收到了：%s", msg_p->data.c_str());
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "listener");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter", 10, Msg_callback);

    ros::spin();
    return 0;
}
