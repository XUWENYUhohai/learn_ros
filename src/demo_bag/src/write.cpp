#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/String.h>

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"rosbag_write");
    ros::NodeHandle nh;//! 使用ros::time需要
    //创建bag对象
    rosbag::Bag bag;
    //打开
    //直接test.bag为相对路径，在learn_ros_ws空间下
    bag.open("/home/xuwenyu/learn_ros_ws/src/demo_bag/bag/test.bag",rosbag::BagMode::Write);
    std_msgs::String msg;//std::string无法传入
    msg.data = "hello";
    bag.write("/chatter",ros::Time::now(),msg);
    bag.write("/chatter",ros::Time::now(),msg);
    bag.write("/chatter",ros::Time::now(),msg);
    bag.write("/chatter",ros::Time::now(),msg);
    bag.write("/chatter",ros::Time::now(),msg);
    //关闭
    bag.close();
    return 0;
}
