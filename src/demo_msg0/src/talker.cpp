// 1.包含头文件 
#include <ros/ros.h>
#include <std_msgs/String.h>//普通文本类型的消息,消息/服务的类型（type）为功能包（package）名/（.msg/.srv）文件名
#include <sstream>//https://www.runoob.com/cplusplus/cpp-libs-sstream.html

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    //2.初始化 ROS 节点:命名(唯一)
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    ros::init(argc, argv, "talker");

    //3.实例化 ROS 句柄
    ros::NodeHandle nh;//该类封装了 ROS 中的一些常用功能，向ROS master注册节点信息

    //4.实例化 发布者 对象
    //泛型: 发布的消息类型
    //参数1: 要发布到的话题
    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 10);

    //5.组织被发布的数据，并编写逻辑发布数据
    //数据(动态组织)
    std_msgs::String msg;
    msg.data = "你好！";
    std::string msg_front = "Hello";
    int count = 0;

    ros::Rate r(1);//逻辑(一秒1次)

    while (ros::ok())
    {
        //使用 stringstream 拼接字符串与编号
        std::stringstream ss;
        ss << msg_front << count;
        msg.data = ss.str();

        pub.publish(msg);//发布消息

        // c_str() 函数可以将 const string* 类型 转化为 cons char* 类型, 就是将C++的string转化为C的字符串数组，c_str()生成一个const char *指针，指向字符串的首地址
        ROS_INFO("发送消息：%s", msg.data.c_str());

        r.sleep(); //根据前面制定的发送贫频率自动休眠 休眠时间 = 1/频率；
        count++;

        //此时无应用
        ros::spinOnce();//此时才会处理回调函数，https://blog.csdn.net/qq_42257666/article/details/131491005
    }
    
    
    return 0;
}
