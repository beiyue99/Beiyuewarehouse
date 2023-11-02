Linux 
1596695493迷你

wjf666666@gmail.com
wujunfeng666666@qmail.com








ip addr show查看可用网络接口

sudo ifconfig ens33 up   启用

sudo dhclient - v ens33  添加ipv4地址





sudo -i切换管理员权限登录
su username 切换到username这个用户
adduser username 添加用户

less可以查看文件内容 上下换行，空格翻页
使用which 可以查找指定文件的路径
find加路径加type加类型
find+路径+-size+范围
find+路劲+ -name +文件名



查找所有空文件夹并删除它们：find / path / to / search - type d - empty - exec rmdir{} \;
find: 查找命令。
/ path / to / search : 要查找的目录路径。
- type d : 查找类型为目录的文件。
- empty : 查找空目录。
- exec : 对查找到的结果执行后面的命令。
rmdir : 删除目录命令。
{} : 在 - exec命令中代表查找到的结果，{}会被实际的结果替换。
\; : 在 - exec命令中，必须以\; 结尾，表示命令结束。






grep - r 加要查找的字符串 加路径        
如果不是目录，可以不加-r，如果要查找不存在该字符串的内容，需要加上-v，
如果不在意大小写，需要加上-i，加上-n是显示行号





tar-cvf t1.tar a  b c    生成归档文件
参数t公开查看档案文件中包含的文件
参数c用来生成一个新的打包文件
参数x用来解开档案文件
参数v用来显示解档和归档过程
参数f用于指定压缩文件的名称和路径

tar加 - z可以一次性压缩，如
tar - czvf t1.tar.gz a b c
tar - cjvf t1.tar.bz2 a b c
也可以一次性解压
加上 - C是解压到指定目录，如
tar - xzvf t1.tar.gz - C . / c    解压到c目录
//tar只负责打包文件，但不压缩，用gzip可以压缩tar打包后的文件，如gizp test.tar。
//- d是解压(gunzip也是这个作用)， - r是压缩所有目录。
bzip2用法与gzip相似，这个命令直接对文件进行压缩，不会新复制一份出来。
跟gzip一样，不能直接压缩目录，需要先用tar打包一下

zip没有 - d  只有unzip，并且不需要指明后缀
zip a  a b c   生成a.zip  ，第一个a为指定的压缩文件名称
unzip - d ./ b a.zip     将名为a.zip解压缩的文件和目录放在名为b的子目录下。需要注意的是，
如果当前目录下已经存在名为b的目录，那么该目录下的所有东西将会被覆盖，因此在执行该命令前需要确认是否已经存在同名目录。
如果不想在解压缩后创建子目录，可以省略 - d选项，直接将解压缩的文件放在当前目录下。当前目录下不存在名为b的目录，则会自动创建该目录。






ln 加文件 加 硬链接名，如
ln z z_hard
硬链接不可以是目录
可用stat命令查看文件信息，如
stat z z_hard

加上-s可以创建符号链接，即软链接





重定向：

> 代表重定向 > text.txt  重定向到test.txt里面，会覆盖原来文件的内容，若改用 >> 会以追加的方式重定向到文件中
2 > 和2 >> 是重定向标准错误输出 / dev / null  是黑洞文件
& > 是标准输出和标准错误输出全部重定向到文件









读，写，执行对应的权限为4，2，1满格权限为7
讲a文件设置权限
chmod u=rwx，g=rx，o=r   a
等价于 chmod 0754 a
chmod -R 777 a 递归改变a以及其内的目录及文件权限
chown root a  把文件a所有者改为root
chown   ：root a  把文件a所有组改为root
chown root ：root a  把文件a所有者和所有组都改为root
chgrp root a  将文件a所有组改为root


-E 预处理 发生宏替换，去注释
gcc -E hello.c -o hello.i
-S编译 转化为汇编代码，汇编文件后缀为.s
-c 把汇编文件生成目标文件，目标文件后缀为.o
-o  链接生成可执行文件名字
gcc hello.o -o a.out

gcc -v查看版本号 -g 包含调试信息-Wall 显示出所有警告,在后面再接一个 -Werror 如果存在警告则编译不会通过



制作静态库，先生成对应的.o文件，再借助ar工具 将.o文件打包为.a文件 libtest.a，
ar工具的三个参数 ： r：更新  c：创建  s：建立索引 ar -rcs libtest.a add.o sub.o
-I(大写i）指定 头文件的路径
-L指定连接时需要的库的路径
-l(小写L)指定链接时所需要的库的名字
gcc test.c -I./ -L./ -ltest



制作动态库
动态库制作，第一步先用fpic生成与地址无关的编译程序.o
gcc -fpic -c add.c sub.c
第二步，借助-shared生成共享库，后缀为.so
gcc -shared add.o sub.o -o libaa.so
//这两步可以合并为  gcc -fpic -shared add.c sub.c -o libaa.so
然后
gcc test.c -I./ -L./ -laa运行a.out出错
这是因为连接器找不到库
解决办法一： 拷贝库
sudo cp libaa.so /lib 然后不需要指定库位置
gcc test.c -I./  -laa 此时运行a.out就可以了，但这是临时设置，重启就失效了


系统加载可执行代码的时候，我们给出了其所依赖库的名字，但还需要知道绝对路径，此时就需要动态载入器。

解决办法二： export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/wjf/dir1
然后再执行a.out就不会报错，这是临时设置
unset LD_LIBRARY_PATH是清除路径
echo是查看路径

解决办法三：
sudo vim ～/.bashrc   打开配置文件，在最后一行写入路径，保存退出。然后
source ～/.bashrc 更新生效，并永久生效


解决方法四：
 sudo vim /etc/ld.so.conf将路径写入配置文件，然后更新一下，sudo ldconfig


解决方法五：
创建符号链接，把当前目录的libaa.so 创建于lib目录







动态链接:不会把代码编译到二进制文件中, 而是在运行时才去加载, 所以只需要维护一个地址
- fPIC产生位置无关的代码
- shared共享
- (小L)指定动态库
- (大i)指定头文件目录, 默认当前目录
- L手动指定库文件搜索目录, 默认只链接共享目录

//静态库编译的时候指定一下库文件所在目录，编译完成之后，可以把库删掉，因为编译的时候，已经把静态库加载到了项目里





/ usr / local / lib 和 / lib 都是存储动态链接库的目录，不过它们的区别如下：

/ usr / local / lib 是用来存储本地安装的软件的库文件，即自行编译安装的软件库，
而不是通过系统包管理器安装的库文件。这个目录通常不包含系统自带的库文件，而是由管理员或用户自己安装的库文件。
/ lib 则是系统自带的库文件所在目录，用来存放操作系统自带的库文件。

如果将库文件放在程序所在目录下，可以确保程序在运行时可以找到库文件，这对于个人编写的小型应用程序是可行的，
但是如果需要在其他程序中重复使用该库文件，就需要在每个程序所在目录下都拷贝一份库文件，这会浪费磁盘空间，并且不方便维护。

相反，如果将库文件放在系统级别的 / usr / local / lib 目录中，其他程序也可以访问该库文件，这可以提高库文件的可重用性，
避免了在多个程序中重复拷贝库文件的麻烦。因此，后续的Makefile将路径添加到该目录


echo > ./test    清空文件内容







先把include放入 vc++的包含目录，然后把静态库放入vc++的库目录，然后把库名放入链接器、输入下的依赖项，最后把动态库直接粘进去


/ etc / shadow是Linux系统中存储用户密码信息的文件。在该文件中，每个用户的密码都被加密存储，以保障用户密码的安全性。
因为该文件存储的是用户密码信息，因此只有root用户及具有特权的用户才有访问该文件的权限。




a.在Linux系统上创建用户组student，新建用户stu1，将其添加到student组，并为其设置家目录和密码的步骤：



1、打开终端并以root用户身份登录。

2、创建用户组student，可以使用以下命令：groupadd student

3、创建用户stu1并将其添加到student组，可以使用以下命令：useradd - g student - d / usr / local / stu1 stu1
这个命令将stu1添加到student组，设置stu1的家目录为 / usr / local / stu1。

4、为用户stu1设置密码，可以使用以下命令：passwd stu1
此命令将提示您输入密码。输入两次以确认密码。现在，用户stu1已创建，其所属的用户组为student，家目录为 / usr / local / stu1，且已经设置密码。

5、通过以下命令确认用户已成功创建并具有正确的属性：id stu1

6、通过以下命令检查stu1的家目录是否正确：ls - ld / usr / local / stu1
会出错，原因是在执行 useradd 命令时，系统会自动创建用户的家目录，但有时可能需要手动创建。
使用以下命令创建名为stu1的用户的家目录：mkdir / usr / local / stu1
然后，使用 chown 命令将目录所有权更改为stu1用户和student组，如下所示：chown stu1 : student / usr / local / stu1
这将确保stu1用户和student组具有对该目录的完全访问权限。现在，您应该能够使用 ls - ld / usr / local / stu1 命令查看目录并确认其权限。








b.使用默认参数新建stu2用户，并设置密码，将stu2附加到student组中，
查看文件 / etc / passwd、 / etc / shadow、 / etc / group中关于stu1、stu2用户，
及student和stu2组的信息，将stu2从student组中删除。

1、useradd stu2  passwd stu2
2、usermod - a - G student stu2  这将将stu2用户添加到student组中。
3、cat / etc / passwd | grep stu 查看 / etc / passwd文件中的用户列表：
4、cat / etc / shadow | grep stu  查看 / etc / shadow文件中的用户列表和密码哈希值：
5、cat / etc / group | grep stu   查看 / etc / group文件中的用户组列表：
6、deluser stu2 student  将stu2用户从student组中删除



c.查看 / etc / shadow中stu1用户信息，锁定用户stu1用户，比较锁定前后 / etc / shadow中文件中stu1用户信息的变化，
在字符控制台分别使用stu1和stu2登录，比较测试结果，解锁stu1用户。


1、要查看 / etc / shadow中stu1用户的信息，可以使用以下命令
sudo cat / etc / shadow | grep stu1

2、要锁定stu1用户，可以使用以下命令：
sudo passwd - l stu1
锁定后，可以再次使用以上命令查看 / etc / shadow中的stu1用户信息，发现其密码区域会出现!标记，表示该用户被锁定了。
接下来，在字符控制台分别使用stu1和stu2登录进行测试，可以发现stu1用户无法登录，而stu2用户可以正常登录。

3、要解锁stu1用户，可以使用以下命令：
sudo passwd - u stu1
解锁后，stu1用户的密码区域中的!标记会被移除，该用户将恢复正常登录状态。




d.创建目录 / right，查看该目录文件详细信息，切换到用户stu1，测试stu1用户是否能够在该目录下创建文件。再切换回root用户，修改 / right目录文件权限位，
使得stu1用户能够在下面创建文件一个名为stu1_file的文件，内容为“echo this is stu1_file”


注意：right的所有者不是stu1，后面无法用stu1进行操作，需要执行sudo chown stu1 : student / right修改目录所有者

切换到用户 stu1：$ su stu1  echo "echo this is stu1_file" > stu1_file





e.以数字方式修改文件 / right / stu1_file文件权限属性，要求所属用户及用户组权限为读、写、可执行，其他用户只读


sudo chmod 754 / right / stu1_file

第一个数字 7 表示所属用户（即 stu1 用户）的权限为读、写、可执行（二进制 111）。
第二个数字 5 表示用户组（即 student 组）的权限为读、可执行（二进制 101）。
第三个数字 4 表示其他用户的权限为只读（二进制 100）。
这样设置后，stu1 用户就可以读写执行 / right / stu1_file 文件，student 组中的其他用户可以读取该文件，而其他用户无法修改该文件。




f.不改变文件 / right / stu1_file的权限属性，使stu2用户对该文件具有读、写、可执行权限，
切换到stu2，修改文件内容为“echo this is stu1_file modified by stu2”，并执行该文件。

1、可以使用如下命令将stu2用户添加到student用户组中：
sudo usermod - a - G student stu2

2、su stu2
cd / right
echo "echo this is stu1_file modified by stu2" > stu1_file
chmod + x stu1_file
. / stu1_file

chmod + x stu1_file命令是将stu1_file文件的可执行权限打开，即加上了执行的权限。
执行. / stu1_file则是在当前目录下执行stu1_file文件，由于已经具有可执行权限，因此会执行该文件并输出结果。

/ right / stu1_file 的所属用户组被修改为 student，而 stu2 用户被添加到该用户组中，所以 stu2 用户可以对该文件具有相应的读、写、执行权限。

//这个方法没用，因为用户所属组也没有修改权限，看下面这个方法

即使将stu2用户加入student用户组中，也无法直接通过所属组修改文件的权限，因为当前文件的所属组权限是只读，不能进行修改操作。
如果要使stu2用户对文件具有读、写、可执行权限，可以使用ACL（访问控制列表）来设置。
可以使用以下命令来为文件添加ACL：sudo setfacl - m u : stu2:rwx / right / stu1_file
该命令将为文件 / right / stu1_file添加一个ACL条目，允许用户stu2读、写、可执行该文件。






h.删除用户stu1、stu2及所有数据，删除用户组student，删除目录 / right

sudo userdel - r stu1
sudo userdel - r stu2
sudo groupdel student
sudo rm - rf / right



i.添加以自己姓名拼音全称为用户名，并把此用户添加到sudo组中，并切换到添加的用户，使用sudo命令测试是否添加成功

1、adduser zhangsan
2、运行以下命令将新用户添加到sudo组中：usermod - aG sudo zhangsan




df - Th /
该命令将以易于理解的格式显示根分区的磁盘使用情况和分区类型。其中，“ - T”选项用于显示分区类型，“ - h”选项用于以易于理解的格式显示磁盘使用情况。


du - sh / boot
该命令将以易于理解的格式显示 / boot目录的总大小。其中，“ - s”选项用于仅显示总大小，“ - h”选项用于以易于理解的格式显示大小。





要将主机名更改为wjf - virtual - machine，可以使用以下命令：sudo hostnamectl set - hostname wjf - virtual - machine



SSH是一种安全的远程登录协议，它通常使用22号端口进行通信。在Linux系统中，sshd是SSH服务器程序的守护进程，它负责监听端口、处理客户端请求等。
在你的系统中，你可以看到两个进程，一个监听IPv4地址，一个监听IPv6地址，这是因为系统同时支持IPv4和IPv6网络协议。



启动和关闭防火墙 sudo ufw enable    sudo ufw disable



可以使用以下命令来测试ssh连接：
ssh <username>@<hostname>

rm - i ./*.swp  删除当前目录的.swp文件

























