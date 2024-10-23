#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <demo_action/addAction.h>
/*  
    需求:
        创建两个ROS节点，服务器和客户端，
        客户端可以向服务器发送目标数据N（一个整型数据）
        服务器会计算1到N之间所有整数的和，这是一个循环累加的过程，返回给客户端，
        这是基于请求响应模式的，
        又已知服务器从接收到请求到产生响应是一个耗时操作，每累加一次耗时0.1s，
        为了良好的用户体验，需要服务器在计算过程中，
        每累加一次，就给客户端响应一次百分比格式的执行进度，使用action实现。
    流程:
        1.包含头文件;
        2.初始化ROS节点;
        3.创建NodeHandle;
        4.创建action服务对象;
        5.处理请求,产生反馈与响应;
        6.spin().
*/

typedef actionlib::SimpleActionServer<demo_action::addAction> Server;//重定义

void cb(const demo_action::addGoalConstPtr& goal,Server* server)//! 必须是server指针，不能是引用
{
    //获取目标值
    int num = goal->num;
    ROS_INFO("目标值：%d",num);
    //累加并响应连续反馈
    int result = 0;
    demo_action::addFeedback feedback;//连续反馈
    ros::Rate rate(10);
    for (size_t i = 1; i <= num; i++)
    {
        result += i;
        //组织连续数据并发布
        feedback.progress_bar = i / (double)num;
        server->publishFeedback(feedback);
        rate.sleep();
    }
    //设置最终结果
    demo_action::addResult r;
    r.result = result;
    server->setSucceeded(r);
    ROS_INFO("最终结果:%d",r.result);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("action服务端实现");
    // 2.初始化ROS节点;
    ros::init(argc,argv,"add_server");
    // 3.创建NodeHandle;
    ros::NodeHandle nh;
    // 4.创建action服务对象;
    /*SimpleActionServer(ros::NodeHandle n, 节点名
                        std::string name, 服务名
    boost::function<void (const demo01_action::AddIntsGoalConstPtr &)> execute_callback, 回调函数
    bool auto_start)是否自动启动，false时需要调用server.start()启动
    */
    // actionlib::SimpleActionServer<demo_action::addAction> server(上面的);
    Server server(nh,"add",boost::bind(&cb,_1,&server),false);//https://www.cnblogs.com/cenima/p/17894353.html   https://blog.csdn.net/wjydym/article/details/92214349
    // 不向 fun 绑定任何参数
    // boost::bind(&fun, _1, _2)   // _1 _2 都是占位符. 上边已经说过了.
    // 所以它就是 将新函数对象在调用时的实参表的第1个参数和第2个参数 绑定到fun函数.  
    server.start();
    // 5.处理请求,产生反馈与响应;
    // 6.spin().   
    ros::spin();
    return 0;
}

// PS:可以先配置CMakeLists.tx文件并启动上述action服务端，然后通过 rostopic 查看话题，向action相关话题发送消息，或订阅action相关话题的消息。
// 例：rostopic list
// 	rostopic pub /add/goal + 两次tab补齐，修改num
// 	rostopic echo /add/feedback

