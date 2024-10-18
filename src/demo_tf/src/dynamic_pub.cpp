/*  动态的坐标系相对姿态发布(一个坐标系相对于另一个坐标系的相对姿态是不断变动的)
需求: 启动 turtlesim_node,该节点中窗体有一个世界坐标系(左下角为坐标系原点)，乌龟是另一个坐标系，键盘
    控制乌龟运动，将两个坐标系的相对位置动态发布
    实现分析: 1.乌龟本身不但可以看作坐标系，也是世界坐标系中的一个坐标点
            2.订阅 turtle1/pose,可以获取乌龟在世界坐标系的 x坐标、y坐标、偏移量以及线速度和角速度
            3.将 pose 信息转换成 坐标系相对信息并发布
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅对象
        5.回调函数处理订阅到的数据(实现TF广播)
            5-1.创建 TF 广播器
            5-2.创建 广播的数据(通过 pose 设置)
            5-3.广播器发布数据
        6.spin
*/

// 1.包含头文件
#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/TransformStamped.h>

// 5.回调函数处理订阅到的数据(实现TF广播)
void doPose(const turtlesim::PoseConstPtr& pose)
{
    //  5-1.创建 TF 广播器
    static tf2_ros::TransformBroadcaster broadcaster;
    //  5-2.创建广播的数据(通过 pose 设置)
    geometry_msgs::TransformStamped ts;
    //  |----头设置
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "world";
    //  |----子坐标系 ID
    ts.child_frame_id = "turtle1";
    //  |----坐标系相对信息设置
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;// 二维实现，pose 中没有z，z 是 0
    //  |--------- 四元数设置
    tf2::Quaternion q;
    q.setRPY(0, 0, pose->theta);
    ts.transform.rotation.x = q.x();
    ts.transform.rotation.y = q.y();
    ts.transform.rotation.z = q.z();
    ts.transform.rotation.w = q.w();
    //  5-3.广播器发布数据
    broadcaster.sendTransform(ts);
}

int main(int argc, char  *argv[])
{ 
    setlocale(LC_ALL, "");
    // 2.初始化 ROS 节点
    ros::init(argc, argv, "dynamic_pub");
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建订阅对象
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 1000, doPose);
    
    // 6.spin
    ros::spin();
    return 0;
}
