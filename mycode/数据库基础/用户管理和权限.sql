1.查询用户
USE mysql;
SELECT* FROM user;
2.
创建用户
CREATE USER '用户名'@'主机名'IDENTIFIED BY'密码';


创建用户
itcast, 能够在当前主机Loca1host访问, 密码123456;
create user 'itcast'@'localhost'identified by '123456';        

--创建用户heima,
可以在任意主机访问该数据库, 密码123456:
create user 'heima'@'%'identified by '123456';




3.
修改用户密码
ALTER USER'用户名'@'主机名'IDENTIFIED WITH mysql_native_ password BY'新密码';

修改用户heima的访问密码为1234 :
alter user 'heima'@'%'identified with mysql_native_password by 1234;




4.删除用户
DROP USER'用户名'@'主机名';

drop user 'heima'@'%';    删除heima用户




SELECT CURRENT_USER();   查看当前用户
SELECT User, Host FROM mysql.user;  查看所有用户
SELECT User, Host FROM mysql.user WHERE User = 'your_username';  查看特定用户








DCL - 权限控制
1.查询权限
SHOW GRANTS FOR '用户名'@'主机名';








2.授予权限
GRANT权限列表ON 数据库名.表名 TO‘用户名'@'主机名';


grant all on itcast.* to 'heima'@'%';

//不授权之前，show databases;  看不到itcast数据库，授权后可以看到
3.撤销权限
REVOKE权限列表ON数据库名.表名 FROM‘用户名'@'主机名';

--撤销权限
revoke all on itcast.*from 'heima'@'%';



