#include <ros/ros.h>
#include <demo_msg1/Person.h>
//消息/服务的类型名（type）为功能包（package）名/（.msg/.srv）文件名

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "talker_person");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<demo_msg1::Person>("chatter", 1000);//cpp发送方需要加类型，接收方不需要

    //组织被发布的消息，编写发布逻辑并发布消息

    demo_msg1::Person p;
    p.name = "xaskdka";
    p.age = 312;
    p.height = 1.53;

    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(p);
        p.age++;
        ROS_INFO("我叫：%s, 今年：%d, 身高：%f米", p.name.c_str(), p.age, p.height);
        r.sleep();
        ros::spinOnce();//没用到
    }
    

    return 0;
}

