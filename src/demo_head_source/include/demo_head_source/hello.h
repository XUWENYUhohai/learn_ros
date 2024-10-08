//在功能包下的include/功能包名 目录下新建头文件: hello.h，示例内容如下:
//头文件保护，防止重定义（多个cpp文件包含一个h文件），与#pragma once类似，当第一次包含h时，由于未定义_HELLO_H条件为真，
//编译（执行）#endif前代码，若已经定义则忽略这一段代码
//标识符（zhi？）唯一：以头文件大写，标识符前后加上_，“.”也变成_

#ifndef _HELLO_H
#define _HELLO_H

// namespace hello_ns
// {
    class HelloPub
    {
        
    public:
        void run();
    };
// }

#endif

// 注意: 在 VScode 中，为了后续包含头文件时不抛出异常，请配置 .vscode 下 c_cpp_properties.json 的 includepath属性: 
//"/home/用户/工作空间/src/功能包/include/**"(可以在include下打开终端输入pwd复制)