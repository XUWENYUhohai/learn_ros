#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <demo_action/addAction.h>
/*
    流程:
        1.包含头文件;
        2.初始化ROS节点;
        3.创建NodeHandle;
        4.创建action客户端对象;
        5.发送目标，处理反馈以及最终结果;
        6.spin().
*/

typedef actionlib::SimpleActionClient<demo_action::addAction> Client;

//处理最终结果
void done_cb(const actionlib::SimpleClientGoalState& state,const demo_action::addResultConstPtr& result)
{
    if (state.state_ == state.SUCCEEDED)
    {
        ROS_INFO("最终结果：%d",result->result);
    }
    else
    {
        ROS_INFO("任务失败！");
    }
    
}

//服务已经激活
void active_cb()
{
    ROS_INFO("服务已经被激活....");
}

//处理连续反馈
void feedback_cb(const demo_action::addFeedbackConstPtr& feedback)
{
    ROS_INFO("当前进度:%.2f",feedback->progress_bar);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点;
    ros::init(argc,argv,"add_client");
    // 3.创建NodeHandle;
    ros::NodeHandle nh;
    // 4.创建action客户端对象;
    // SimpleActionClient(ros::NodeHandle & n, const std::string & name, bool spin_thread = true)//!true则启动另一线程运行action
    // actionlib::SimpleActionClient<demo_action::addAction> client(nh,"add");
    Client client(nh,"add",true);

    //等待服务启动, 只可以使用client.waitForServer();,之前服务中等待启动的另一种方式ros::service::waitForService("add");不适用
    client.waitForServer();

      // 5.发送目标，处理反馈以及最终结果;
    /*  
        void sendGoal(const demo01_action::AddIntsGoal &goal, 
            boost::function<void (const actionlib::SimpleClientGoalState &state, const demo01_action::AddIntsResultConstPtr &result)> done_cb, 
            boost::function<void ()> active_cb, 
            boost::function<void (const demo01_action::AddIntsFeedbackConstPtr &feedback)> feedback_cb)
    */
    demo_action::addGoal goal;
    goal.num = 10;

    client.sendGoal(goal,&done_cb,&active_cb,&feedback_cb);
    // 6.spin().
    ros::spin();
    return 0;
}

