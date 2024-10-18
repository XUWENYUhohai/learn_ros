//1.包含头文件
#include <ros/ros.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/PointStamped.h>

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"dynamic_sub");
    // 3.创建 TF 订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);
    while (ros::ok())
    {
        geometry_msgs::PointStamped point_turtle1;
        //!或ros::Time(0.0)表示此时无时间戳（时间戳无值），不能用ros::Time::now()，buffer里有一堆值每个都有时间戳，ros会将坐标点的时间戳与坐标转换的时间戳比较，时间接近才能转换
        point_turtle1.header.stamp = ros::Time();
        point_turtle1.header.frame_id = "turtle1";
        point_turtle1.point.x = 1;
        point_turtle1.point.y = 1;
        point_turtle1.point.z = 0;
        // 5.转换坐标点(相对于父级坐标系)
       	//新建一个坐标点，用于接收转换结果  
        //使用 try 语句或休眠，否则可能由于缓存接收延迟而导致坐标转换失败
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_turtle1,"world");
            ROS_INFO("坐标点相对于 world 的坐标为:(%.2f,%.2f,%.2f)",point_base.point.x,point_base.point.y,point_base.point.z);
            
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("程序异常:%s",e.what());
        }
        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}


