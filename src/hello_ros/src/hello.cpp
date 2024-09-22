#include "ros/ros.h"
#include <iostream>
//main 函数的参数不可以被 const 修饰
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");//当ROS__INFO 终端输出有中文时，会出现乱码,或  setlocale(LC_CTYPE, "zh_CN.utf8");
    //执行 ros 节点初始化
    ros::init(argc, argv, "hello");
    //创建 ros 节点句柄(非必须)
    ros::NodeHandle n;
    //控制台输出 hello_ros
    ROS_INFO("helo_ros");
    ROS_INFO("helo_ros");
    ROS_INFO("helo_确切");
    ROS_INFO("helo_ros");
    ROS_INFO("helo_ros");
    ros::spin();
    return 0;
}

// 先启动命令行1：roscore
// 再启动命令行2：
// cd 工作空间
// source ./devel/setup.bash（source命令用于执行文本文件中的一连串指令）
// rosrun 包名 C++节点（hello）

// 为了方便可以：echo "source ~/工作空间/devel/setup.bash" >> ~/.bashrc
// ~/.bashrc为终端程序的初始化脚本