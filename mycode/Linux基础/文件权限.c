
读，写，执行对应的权限为4，2，1满格权限为7
讲a文件设置权限
chmod u = rwx，g = rx，o = r   a
等价于 chmod 0754 a
chmod - R 777 a 递归改变a以及其内的目录及文件权限
chown root a  把文件a所有者改为root
chown   ：root a  把文件a所有组改为root
chown root ：root a  把文件a所有者和所有组都改为root
chgrp root a  将文件a所有组改为root




e.以数字方式修改文件 / right / stu1_file文件权限属性，要求所属用户及用户组权限为读、写、可执行，其他用户只读


sudo chmod 754 / right / stu1_file

第一个数字 7 表示所属用户（即 stu1 用户）的权限为读、写、可执行（二进制 111）。
第二个数字 5 表示用户组（即 student 组）的权限为读、可执行（二进制 101）。
第三个数字 4 表示其他用户的权限为只读（二进制 100）。
这样设置后，stu1 用户就可以读写执行 / right / stu1_file 文件，student 组中的其他用户可以读取该文件，而其他用户无法修改该文件。