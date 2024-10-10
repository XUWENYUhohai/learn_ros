#include <ros/ros.h>
#include <std_msgs/String.h>
// 全局(话题参考ROS系统，与节点命名空间平级)
// 相对(话题参考的是节点的命名空间，与节点名称平级)
// 私有(话题参考节点名称，是节点名称的子级)
int main(int argc, char  *argv[])
{
    // 1.初始化节点设置一个节点名称
    // ros::init(argc,argv,"hello")
    // 2.设置不同类型的话题
    // 3.启动节点时，传递一个 __ns:= xxx
    // 4.节点启动后，使用 rostopic 查看话题信息 
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh;

    // 全局名称(话题参考ROS系统，与节点命名空间平级)
    // 格式:以/开头的名称,和节点名称无关
    // 比如:/xxx/yyy/zzz
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter", 1000);//结果1:/chatter
    //ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter/money",1000);//结果2:/chatter/money


    // 相对名称(话题参考的是节点的命名空间，与节点名称平级)
    // 格式:非/开头的名称,参考命名空间(与节点名称平级)来确定话题名称
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);//结果1:xxx/chatter
    //ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter/money",1000);//结果2：xxx/chatter/money

    // 私有名称(话题参考节点名称，是节点名称的子级)
    // 格式:以~开头的名称
    // ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);//结果1:/xxx/hello/chatter
    //ros::Publisher pub = nh.advertise<std_msgs::String>("chatter/money",1000);//结果2：/xxx/hello/chatter/money

    //PS:当使用~,而话题名称有时/开头时，那么话题名称是绝对的
    //ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter/money",1000);//结果3:/chatter/money
    return 0;
}
