/*实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin

    需求：描述:现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，son1 相对于 world，
    以及 son2 相对于 world 的关系是已知的，求 son1原点在 son2中的坐标，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
*/

//1.包含头文件
#include <ros/ros.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
// #include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"many_sub");
     // 4.创建 TF 订阅对象
    tf2_ros::Buffer buffer;//可以不用buffer头文件
    tf2_ros::TransformListener listener(buffer);
    // 5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
    ros::Rate r(1);
    while (ros::ok())
    {
        try
        {
            //   解析 son1 中的点相对于 son2 的坐标
            geometry_msgs::TransformStamped ts = buffer.lookupTransform("son2","son1",ros::Time(0));
            ROS_INFO("Son1 相对于 Son2 的坐标关系:父坐标系ID= %s",ts.header.frame_id.c_str());
            ROS_INFO("Son1 相对于 Son2 的坐标关系:子坐标系ID= %s",ts.child_frame_id.c_str());
            ROS_INFO("Son1 相对于 Son2 的坐标关系: x = %.2f, y = %.2f, z = %.2f",ts.transform.translation.x,ts.transform.translation.y,ts.transform.translation.z);

            geometry_msgs::PointStamped point_son1;
            point_son1.header.stamp = ros::Time::now();
            point_son1.header.frame_id = "son1";
            point_son1.point.x = 1.0;
            point_son1.point.y = 2.0;
            point_son1.point.z = 3.0;

            geometry_msgs::PointStamped point_son2;
            point_son2 = buffer.transform(point_son1,"son2");
            ROS_INFO("在 Son2 中的坐标:x=%.2f,y=%.2f,z=%.2f",
                    point_son2.point.x,
                    point_son2.point.y,
                    point_son2.point.z);
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_WARN("异常信息：%s",e.what());
        }
        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
