/*  
    订阅 turtle1 和 turtle2 的 TF 广播信息，查找并转换时间最近的 TF 信息
    将 turtle1 转换成相对 turtle2 的坐标，在计算线速度和角速度并发布*/

//1.包含头文件
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
// #include <geometry_msgs/TransformStamped.h> //!可以不用
#include <tf2_ros/transform_listener.h>
// #include <tf2_geometry_msgs/tf2_geometry_msgs.h>//!注意: 调用 transform 必须包含该头文件


int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"turtle_frames_sub");
    // 3.创建 ros 句柄
    ros::NodeHandle nh;
    // 4.创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    // 5.处理订阅到的 TF
    // 需要创建发布 /turtle2/cmd_vel 的 publisher 对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);

    ros::Rate r(10);
    while (ros::ok())
    {
        try
        {
            //5-1.先获取 turtle1 相对 turtle2 的坐标信息
            geometry_msgs::TransformStamped ts = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
             //5-2.根据坐标信息生成速度信息 -- geometry_msgs/Twist.h
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(ts.transform.translation.x,2) + pow(ts.transform.translation.y,2));//0.5和4是系数随便设的
            twist.angular.z = 4 * atan2(ts.transform.translation.y,ts.transform.translation.x);
            //5-3.发布速度信息 -- 需要提前创建 publish 对象
            pub.publish(twist); 
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("错误提示:%s",e.what());
        }
        r.sleep();
        // 6.spin
        ros::spinOnce();
    }

    
    return 0;
}
