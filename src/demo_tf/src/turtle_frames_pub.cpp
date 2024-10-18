// 可以订阅乌龟的位姿信息，然后再转换成坐标信息，两只乌龟的实现逻辑相同，只是订阅的话题名称，生成的坐标信息等稍有差异，可以将差异部分通过参数传入:
// 该节点需要启动两次
// 每次启动时都需要传入乌龟节点名称(第一次是 turtle1 第二次是 turtle2)
/*  该文件实现:需要订阅 turtle1 和 turtle2 的 pose，然后广播相对 world 的坐标系信息
    注意: 订阅的两只 turtle,除了命名空间(turtle1 和 turtle2)不同外,
          其他的话题名称和实现逻辑都是一样的，
          所以我们可以将所需的命名空间通过 args 动态传入
    实现流程:
        1.包含头文件
        2.初始化 ros 节点
        3.解析传入的命名空间
        4.创建 ros 句柄
        5.创建订阅对象
        6.回调函数处理订阅的 pose 信息
            6-1.创建 TF 广播器
            6-2.将 pose 信息转换成 TransFormStamped
            6-3.发布
        7.spin
*/
//1.包含头文件
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
//保存乌龟名称
std::string turtle_name;

//https://blog.csdn.net/weixin_53432918/article/details/131640124
void turtle_pose_callback(const turtlesim::PoseConstPtr& pose)
{
    //  6-1.创建 TF 广播器 ---------------------------------------- 注意 static
    static tf2_ros::TransformBroadcaster broadcaster;//static使广播器只初始化一次
    //  6-2.将 pose 信息转换成 TransFormStamped
    geometry_msgs::TransformStamped ts;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "world";
    ts.child_frame_id = turtle_name;
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0;

    tf2::Quaternion q;
    q.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = q.getX();
    ts.transform.rotation.y = q.getY();
    ts.transform.rotation.z = q.getZ();
    ts.transform.rotation.w = q.getW();
    //  6-3.发布
    broadcaster.sendTransform(ts);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"turtle_frames_pub");
    // 3.解析传入的命名空间
    if (argc != 2)
    {
        ROS_ERROR("请传入正确的参数");
    }
    else
    {
        turtle_name = argv[1];
        ROS_INFO("乌龟 %s 坐标发送启动",turtle_name.c_str());
    }
    // 4.创建 ros 句柄
    ros::NodeHandle nh;
    // 5.创建订阅对象
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose",1000,turtle_pose_callback);
    // 6.回调函数处理订阅的 pose 信息
    // 7.spin
    ros::spin();
    return 0;
}
