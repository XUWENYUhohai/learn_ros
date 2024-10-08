#include <ros/ros.h>
// #include <demo_head_source/hello.h>
#include "demo_head_source/hello.h"
//1
// namespace hello_ns
// {       
//     void HelloPub::run()
//     {
//         ROS_INFO("自定义头文件使用");
//     }
// } // namespace hello_ns

//2
// void hello_ns::HelloPub::run()
// {
//     ROS_INFO("自定义头文件使用1");
// }

//3
void HelloPub::run()
{
    ROS_INFO("自定义头文件使用2");
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "test_head");

    // hello_ns::HelloPub hp;
    HelloPub hp;
    hp.run();
    return 0;
}
