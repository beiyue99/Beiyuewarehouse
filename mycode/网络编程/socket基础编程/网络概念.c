

Mac地址就是网卡的id  是个物理地址   6个字节  48位
ipv4地址  4个字节 32位	
一个IP将其分为子网id和主机id
子网id和主机id需要和子网掩码一起来看,
10.1.1.2
255.255.255.0
ip中被连续的1覆盖的位就是子网id
ip中被连续的0覆盖的位就是主机id

子网id:10.1.1
主机id:2
网段地址:10.1.1.0
广播地址:10.1.1.255  
给主机设置ip,这两个地址不能用


192.168.1.23/24       (24代表子网掩码为24个1),也就是255.255.255.0



桥接模式：虚拟机和主机一样，能和外部主机通讯
net模式： 主机虚拟出来一个网段，如（192.168.131.0),并虚拟出一个网卡，通过该网段与虚拟机通讯，虚拟机只能跟主机通讯



端口
作用:用来标识应用程序(进程)
port:2个字节0-65535
0-1023知名端口
自定义端口1024-65535



















































































