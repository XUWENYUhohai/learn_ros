#include <ros/ros.h>

// 参数可使用数据类型:
// 32-bit integers(4个字节int),
// booleans,
// strings,
// doubles,
// iso8601 dates（时间,例：日历表示2004-05-03或20040503，时间表示（北京时间）22:30:05+08:00或223005+0800或223005+08）,
// lists（单列集合）,
// base64-encoded binary data,
// 字典（双列集合键值对）

/*
    参数服务器操作之新增与修改(二者API一样)_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle
        setParam("键",值)
    ros::param
        set("键","值")

    示例:分别设置整形、浮点、字符串、bool、列表、字典等类型参数
        修改(相同的键，不同的值)

*/

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "param_set");
    std::vector<std::string> str;
    str.push_back("张三");
    str.push_back("李四");
    str.push_back("王五");

    std::map<std::string, std::string> friends;
    friends.insert(std::pair<std::string, std::string>("a", "b"));
    friends.insert(std::make_pair("c", "d"));
    friends["e"] = "f";

    //NodeHandle--------------------------------------------------------
    ros::NodeHandle nh;
    nh.setParam("nh_int", 10); //整型
    nh.setParam("nh_double", 3.14);//浮点型
    nh.setParam("nh_bool", true);//bool
    nh.setParam("nh_string", "hello");//字符串
    nh.setParam("nh_vector", str); // vector
    nh.setParam("nh_map", friends);// map

    //修改演示(相同的键，不同的值)
    nh.setParam("nh_int",10000);

    //param--------------------------------------------------------------
    ros::param::set("param_int", 20);
    ros::param::set("param_double", 3.14);
    ros::param::set("param_string", "Hello Param");
    ros::param::set("param_bool", false);
    ros::param::set("param_vector", str);
    ros::param::set("param_map", friends);
    return 0;
}
