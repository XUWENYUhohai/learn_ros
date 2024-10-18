/* 静态坐标变换发布方:发布关于 laser 坐标系的位置信息 
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建静态坐标转换广播器
        4.创建坐标系信息
        5.广播器发布坐标系信息
        6.spin()

tf2_geometry_msgs:可以将ROS消息转换成tf2消息。
tf2: 封装了坐标变换的常用消息。
tf2_ros:为tf2提供了roscpp和rospy绑定，封装了坐标变换常用的API。
*/

// 1.包含头文件
#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化 ROS 节点
    ros::init(argc, argv, "static_pub");
    // 3.创建静态坐标转换广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;
    // 4.创建坐标系信息
    geometry_msgs::TransformStamped ts;
    //----设置头信息
    ts.header.seq = 100;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";
    //----设置子级坐标系
    ts.child_frame_id = "laser";
    //----设置子级相对于父级的偏移量
    ts.transform.translation.x = 0.2;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.5;
    //----设置四元数:将 欧拉角数据转换成四元数
    tf2::Quaternion q;
    q.setRPY(0,0,0);
    ts.transform.rotation.x = q.getX();
    ts.transform.rotation.y = q.getY();
    ts.transform.rotation.z = q.getZ();
    ts.transform.rotation.w = q.getW();
    // 5.广播器发布坐标系信息
    broadcaster.sendTransform(ts);
    ros::spin();
    return 0;
}
