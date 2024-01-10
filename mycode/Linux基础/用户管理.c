
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