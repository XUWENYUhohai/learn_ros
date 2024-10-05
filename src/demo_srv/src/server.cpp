#include <ros/ros.h>
#include <demo_srv/num.h>
//消息/服务的类型名（type）为功能包（package）名/（.msg/.srv）文件名

/*
需求: 编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器，服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，客户端再解析
 服务器实现:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建 服务 对象
        5.回调函数处理请求并产生响应
        6.由于请求有多个，需要调用 ros::spin()
*/

// bool 返回值由于标志是否处理成功
bool doReq(demo_srv::num::Request& req, demo_srv::num::Response& resp)
{
    int num1 = req.num1;
    int num2 = req.num2;
    ROS_INFO("服务器接收到的请求数据为:num1 = %d, num2 = %d", num1, num2);

    // if (num1 < 0 || num2 < 0)
    // {
    //     ROS_INFO("提交的数据异常:数据不可以为负数");
    //     return false;
    // }

    resp.sum = num1 + num2;
    return true;
}

//!!！ 不行
bool doReq_ptr(demo_srv::numRequestConstPtr& req, demo_srv::numResponsePtr& resp)
{
    int num1 = req->num1;
    int num2 = req->num2;
    ROS_INFO("服务器接收到的请求数据为:num1 = %d, num2 = %d", num1, num2);

    if (num1 < 0 || num2 < 0)
    {
        ROS_INFO("提交的数据异常:数据不可以为负数");
        return false;
    }

    resp->sum = num1 + num2;
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;
    //创建 服务 对象
    ros::ServiceServer server = nh.advertiseService("add", doReq);
    //! 由于请求有多个，需要调用 ros::spin()
    ros::spin();
    return 0;
}
