#include <ros/ros.h>
#include <demo_head_source/libhaha.h>

//1
// namespace hello_ns
// {       
//     void HelloPub::run()
//     {
//         ROS_INFO("自定义源文件(lib)使用");
//     }
// } // namespace hello_ns

//2
// void hello_ns::HelloPub::run()
// {
//     ROS_INFO("自定义源文件(lib)使用1");
// }

//3
void HelloPub::run()
{
    ROS_INFO("自定义源文件(lib)使用2");
}