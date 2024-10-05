#include <ros/ros.h>
#include <demo_srv/num.h>
/* client实现:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建 客户端 对象
        5.请求服务，接收响应
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // 调用时动态传值,如果通过 launch 的 args 传参，需要传递的参数个数 +3
    // if (argc != 5)//launch 传参(0-文件路径 1传入的参数 2传入的参数 3节点名称 4日志路径)
    if (argc != 3)
    {
        ROS_ERROR("请输入两个整数");
        return 1;
    }
    
    ros::init(argc, argv, "client");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<demo_srv::num>("add");

    //等待服务启动成功
    //方式1
    ros::service::waitForService("add");
    //方式2
    client.waitForExistence();

    // 组织请求数据
    //! 不行
    demo_srv::num::Request a;
    demo_srv::num::Response b;
    a.num1 = atoi(argv[1]);//atoi函数将字符串转为整数
    a.num2 = atoi(argv[2]);//atoi函数将字符串转为整数

    //! 不行
    demo_srv::numRequest c;
    demo_srv::numResponse d;
    c.num1 = atoi(argv[1]);
    c.num2 = atoi(argv[2]);

    //方法3
    demo_srv::num n;
    n.request.num1 = atoi(argv[1]);
    n.request.num2 = atoi(argv[2]);

    // 发送请求,返回 bool 值，标记是否成功    
    // bool flag1 = client.call(a);//没有bool flag也行
    // bool flag2 = client.call(c);
    bool flag3 = client.call(n);

    //处理响应
    if (flag3)
    {
        // ROS_INFO("请求正常处理,响应结果:%d", b.sum);
        // ROS_INFO("请求正常处理,响应结果:%d", d.sum);
        ROS_INFO("请求正常处理,响应结果:%d", n.response.sum);
    }
    else
    {
        ROS_ERROR("请求处理失败....");
        return 1;
    }
    

    return 0;
}
