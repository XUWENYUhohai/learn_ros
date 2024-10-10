#include <ros/ros.h>

int main(int argc, char  *argv[])
{
    // 会在名称后面添加时间戳。
    ros::init(argc, argv, "zhangsan", ros::init_options::AnonymousName);

    // 节点名称设置了命名空间。
    // std::map<std::string, std::string> map;
    // map["__ns"] = "xxx";
    // ros::init(map, "zhangsan"); 
    return 0;
}
