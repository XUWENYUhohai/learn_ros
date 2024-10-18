#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"rosbag_read");
    ros::NodeHandle nh;//! 使用ros::time需要
    //创建 bag 对象
    rosbag::Bag bag;
    //打开 bag 文件
    bag.open("/home/xuwenyu/learn_ros_ws/src/demo_bag/bag/test.bag",rosbag::BagMode::Read);
    //读数据
    //高级for（forrange）：for (auto && i : rosbag::View(bag)){}
    for (rosbag::MessageInstance const m : rosbag::View(bag))
    {
        std::string topic = m.getTopic();
        ros::Time time = m.getTime();
        // std_msgs::StringPtr也可以
        std_msgs::String::ConstPtr p = m.instantiate<std_msgs::String>();//instantiate取出消息的值，返回指针
        if (p != nullptr)
        {
            ROS_INFO("读取消息: %s",p->data.c_str());
        }
    }
    //关闭文件流
    bag.close();
    
    return 0;
}
