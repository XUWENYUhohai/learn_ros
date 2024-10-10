# learn_ros
1.roscore

2.调试F5（需调整launch.json里的"program"，有参数添参数，.launch已测试（需要使用 killall -9 roscore && killall -9 rosmaster 或者 外部使用roscore））

配置：

https://blog.csdn.net/zhaoliang38/article/details/142146951

https://www.jb51.net/article/192889.htm

first：

echo "# learn_ros" >> README.md

git init

git add .

git commit -m "Initial commit"

git remote add origin https://github.com/XUWENYUhohai/learn_ros.git

git branch -M main

git push -u origin main




after:

git add .

git commit -m "修改的信息"

git push



https://zhuanlan.zhihu.com/p/678233404

vscode里的提交

https://www.cnblogs.com/gamepen/p/17753831.html


ctrl + backspace 删除左边字符

ctrl + k + c 注释

ctrl + k + u 取消注释

ctrl + shift + ~ 打开终端（ctrl + alt + c 系统终端）

ctrl + shift + p 设置

ctrl + shift + k 删除行

alt + up/down 移动行

ctrl + f 查找

ctrl + h 替换

ctrl + shift + up/down 选中多行


1.准备

先要保证不同计算机处于同一网络中，最好分别设置固定IP，如果为虚拟机，需要将网络适配器改为桥接模式；

2.配置文件修改

分别修改不同计算机的 /etc/hosts 文件，在该文件中加入对方的IP地址和计算机名:

主机端:

从机的IP    从机计算机名

从机端:

主机的IP    主机计算机名

设置完毕，可以通过 ping 命令测试网络通信是否正常。

IP地址查看名: ifconfig(若未安装先根据提示安装，windows下是ipconfig)

计算机名称查看: hostname

3.配置主机IP

配置主机的 IP 地址

~/.bashrc 追加

export ROS_MASTER_URI=http://主机IP:11311

export ROS_HOSTNAME=主机IP

4.配置从机IP

配置从机的 IP 地址，从机可以有多台，每台都做如下设置:

~/.bashrc 追加

export ROS_MASTER_URI=http://主机IP:11311

export ROS_HOSTNAME=从机IP

测试

1.主机启动 roscore(必须)

2.主机启动订阅节点，从机启动发布节点，测试通信是否正常

3.反向测试，主机启动发布节点，从机启动订阅节点，测试通信是否正常