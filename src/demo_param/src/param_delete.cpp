#include <ros/ros.h>

/* 
    参数服务器操作之删除_C++实现:
    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_delete");

    ros::NodeHandle nh;
    bool flag1 = nh.deleteParam("nh_int");
    ROS_INFO("nh删除结果: %d", flag1);

    bool flag2 = ros::param::del("param_int");
    ROS_INFO("param删除结果: %d", flag2);
    return 0;
}
