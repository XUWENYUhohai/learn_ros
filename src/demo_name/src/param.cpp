#include <ros/ros.h>
//运行时，假设设置的 namespace 为 xxx，节点名称为 yyy
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "yyy");

    //ros::param设置参数
    ros::param::set("/set_A", 100);//全局/,和命名空间以及节点名称无关/set_A
    ros::param::set("set_B", 100);//相对,参考命名空间/xxx/set_B
    ros::param::set("~set_C", 100);//私有~,参考命名空间与节点名称/xxx/yyy/set_C

    // ros::NodeHandle设置参数
    ros::NodeHandle nh;
    nh.setParam("/nh_A", 100);//全局/,和命名空间以及节点名称无关
    nh.setParam("nh_B", 100);//相对,参考命名空间

    ros::NodeHandle nh_private("~");
    nh_private.setParam("nh_C", 100);//私有~,参考命名空间与节点名称
    return 0;
}
