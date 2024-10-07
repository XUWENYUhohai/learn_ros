#include <ros/ros.h>
/*
    ! 注意命名空间的使用。
*/

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "param_color_set");

    //1  //!不行
    // ros::NodeHandle nh("turtlesim");
    // ros::param::set("background_r", 0);
    // ros::param::set("background_g", 0);
    // ros::param::set("background_b", 0);

    //2
    // ros::NodeHandle nh;
    // ros::param::set("turtlesim/background_r", 0);
    // ros::param::set("turtlesim/background_g", 0);
    // ros::param::set("turtlesim/background_b", 0);

    //3
    // ros::NodeHandle nh;
    // nh.setParam("turtlesim/background_r", 0);
    // nh.setParam("turtlesim/background_g", 0);
    // nh.setParam("turtlesim/background_b", 0);

    //4
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r", 0);
    nh.setParam("background_g", 0);
    nh.setParam("background_b", 0);
    return 0;
}

// 方式1:修改小乌龟节点的背景色(命令行实现)
// rosparam set /turtlesim/background_b 自定义数值
// rosparam set /turtlesim/background_g 自定义数值
// rosparam set /turtlesim/background_r 自定义数值
// 修改相关参数后，重启 turtlesim_node 节点，背景色就会发生改变了

// 方式2:启动节点时，直接设置参数
// rosrun turtlesim turtlesim_node _background_r:=100 _background_g:=0 _background_b:=0

// 方式3:通过launch文件传参
// <launch>
//     <node pkg="turtlesim" type="turtlesim_node" name="set_bg" output="screen">
//         <!-- launch 传参策略1 -->
//         <!-- <param name="background_b" value="0" type="int" />
//         <param name="background_g" value="0" type="int" />
//         <param name="background_r" value="0" type="int" /> -->

//         <!-- launch 传参策略2 -->
//         <rosparam command="load" file="$(find demo_turtle)/launch/color.yaml" />
//     </node>
// </launch>