#include <ros/ros.h>
//定时器的回调函数:
    // struct TimerEvent
    // {
    //   Time last_expected;                     ///< 上一回调函数应该发生的时刻
    //   Time last_real;                         ///< 上一回调函数实际发生的时刻

    //   Time current_expected;                  ///< 当前回调函数应该发生的时刻
    //   Time current_real;                      ///< 当前回调函数实际发生的时刻

    //   struct
    //   {
    //     WallDuration last_duration;           ///<包含上一回调的时间间隔（结束时间-开始时间），它始终在 `wall-clock time`
    //   } profile;
    // };
void timer_callback(const ros::TimerEvent& event)
{
    ROS_INFO("-------------");
    ROS_INFO("event_real: %.2f", event.current_real.toSec());
    ROS_INFO("event_expected: %.2f", event.current_expected.toSec());
    ROS_INFO("event_string: %s", std::to_string(event.current_real.toSec()).c_str());//to_string()将数字常量转化为字符串
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ros_time");
    ros::NodeHandle nh;//必须创建句柄，否则时间没有初始化，导致后续API调用失败//! 使用ros::time需要

    //1.时刻
    //获取时刻，或是设置指定时刻:
    ros::Time right_time = ros::Time::now();//将当前时刻封装成对象

    ROS_INFO("当前时刻:%.2f", right_time.toSec());//获取距离 1970年01月01日 00:00:00 的秒数
    ROS_INFO("当前时刻:%d", right_time.sec);//sec不是函数是字段,返回的是整型%d,获取距离 1970年01月01日 00:00:00 的秒数

    ros::Time sometime = ros::Time(100, 1000000000);// 参数1:秒数  参数2:纳秒
    ROS_INFO("时刻:%.2f",sometime.toSec()); //101.00
    ros::Time sometime2(100.3);//直接传入 double 类型的秒数
    ROS_INFO("时刻:%.2f",sometime2.toSec()); //100.30

    //2.持续时间
    //设置一个时间区间(间隔):
    ROS_INFO("当前时刻:%.2f", ros::Time::now().toSec());
    ros::Duration d(10);//持续10秒钟,参数是double类型的，以秒为单位
    d.sleep();//按照指定的持续时间休眠
    ROS_INFO("持续时间:%.2f", d.toSec());//将持续时间换算成秒
    ROS_INFO("当前时刻:%.2f", ros::Time::now().toSec());

    //3.持续时间与时刻运算
    //为了方便使用，ROS中提供了时间与时刻的运算:
    ROS_INFO("时间运算");
    ros::Time now = ros::Time::now();
    ros::Duration dur1(10);
    ros::Duration dur2(20);
    //(1) time 与 duration 运算
    ros::Time before_time = now - dur1;
    ros::Time after_time = now + dur1;
    ROS_INFO("当前时刻之后:%.2f",after_time.toSec());
    ROS_INFO("当前时刻之前:%.2f",before_time.toSec());
    //(2) duration 之间相互运算
    ros::Duration dur3 = dur1 - dur2;
    ros::Duration dur4 = dur1 + dur2;
    ROS_INFO("dur3 = %.2f",dur3.toSec());
    ROS_INFO("dur4 = %.2f",dur4.toSec());
    //PS: time 与 time 不可以运算
    // ros::Time nn = now + before_time;//异常

    //4.设置运行频率
    // ros::Rate rate(1);//指定频率
    // while (true)
    // {
    //     ROS_INFO("-----------code----------");
    //     rate.sleep();//休眠，休眠时间 = 1 / 频率。
    // }

    //5.定时
    //ROS 中内置了专门的定时器，可以实现与 ros::Rate 类似的效果:
    // ROS 定时器
    /**
    * \brief 创建一个定时器，按照指定频率调用回调函数。
    *
    * \param period 时间间隔
    * \param callback 回调函数
    * \param oneshot 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
    * \param autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动。
    */
    //Timer createTimer(Duration period, const TimerCallback& callback, bool oneshot = false,
    //                bool autostart = true) const;
    ros::Timer timer = nh.createTimer(ros::Duration(0.5), timer_callback);
    // ros::Timer timer = nh.createTimer(ros::Duration(0.5), timer_callback, true);//只执行一次

    // ros::Timer timer = nh.createTimer(ros::Duration(0.5), timer_callback, true, false);//需要手动启动
    // timer.start();

    ros::spin();//必须 spin
    return 0;
}
