#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
/*
    编写 ROS 节点，控制小乌龟画圆
    准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建发布者对象
        4.循环发布运动控制消息
*/

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "talker_turtle");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    geometry_msgs::Twist t;
    t.linear.y = 1.0;
    t.angular.z = 2.0;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(t);
        r.sleep();
    }
    
    return 0;
}
