#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <demo_reconfigure/drConfig.h>
 /*  
    动态参数服务端: 参数被修改时直接打印
    实现流程:
        1.包含头文件
        2.初始化 ros 节点
        3.创建服务器对象
        4.创建回调对象(使用回调函数，打印修改后的参数)
        5.服务器对象调用回调对象
        6.spin()
*/

void cb(demo_reconfigure::drConfig& config,uint32_t level)
{
    ROS_INFO("动态参数解析数据：%d, %.2f, %d, %s, %d", config.int_param, config.double_param, config.bool_param, config.string_param.c_str(), config.list_param);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"dr_server");
    // ros::NodeHandle nh;
    // 3.创建服务器对象
    dynamic_reconfigure::Server<demo_reconfigure::drConfig> server;
    // 4.创建回调对象(使用回调函数，打印修改后的参数)
    dynamic_reconfigure::Server<demo_reconfigure::drConfig>::CallbackType cbType;
    // https://blog.csdn.net/wjydym/article/details/92214349
    // 不向 fun 绑定任何参数
    // boost::bind(&fun, _1, _2)   // _1 _2 都是占位符.
    // 所以它就是 将新函数对象在调用时的实参表的第1个参数和第2个参数 绑定到fun函数.  
    cbType = boost::bind(&cb,_1,_2);
    // 5.服务器对象调用回调对象
    server.setCallback(cbType);
    // 6.spin()
    ros::spin();
    return 0;
}
// 先启动roscore
// 启动服务端:rosrun 功能包 xxxx
// 启动客户端:rosrun rqt_gui rqt_gui -s rqt_reconfigure或rosrun rqt_reconfigure rqt_reconfigure
// 最终可以通过客户端提供的界面修改数据，并且修改完毕后，服务端会即时输出修改后的结果。
// PS:ROS版本较新时，可能没有提供客户端相关的功能包导致rosrun rqt_reconfigure rqt_reconfigure调用会抛出异常。
