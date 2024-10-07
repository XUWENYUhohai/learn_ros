#include <ros/ros.h>
#include <demo_msg1/Person.h>

void callback(const demo_msg1::PersonConstPtr& p)
{
    ROS_INFO("订阅者信息：%s, %d, %.2f", p->name.c_str(), p->age, p->height);//%2f是float的所有位数输出2位,%.2f是float后的小数只输出两位
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "listener_person");
    ros::NodeHandle nh;
    
    ros::Subscriber sub = nh.subscribe("chatter", 10, callback);
    if (sub)
    {
        
    }
    ros::spin();
    return 0;
}
