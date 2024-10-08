#include <ros/ros.h>
#include <demo_head_source/libhaha.h>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "test_source");

    HelloPub hp;
    hp.run();
    return 0;
}
