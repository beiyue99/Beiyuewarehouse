1.查询多个字段
SELECT字段1, 字段2, 字段3..FROM表名;
SELECT* FROM表名;


2.设置别名
SELECT字段1[AS别名1], 字段2[AS别名2].FROM表名;


3.去除重复记录
SELECT DISTINCT字段列表FROM表名;



select name, workno, age from emp;   就会从表中只返回这三个数据
select from emp; 会返回整张表


select workaddress as'工作地址'from emp;   as可以省略

select distinct workaddress'工作地址'from emp;




条件查询
1.语法
SELECT字段列表FROM表名WHERE条件列表;

--1.查询年龄等于88的员工
select * from emp where age=88;


2 查询有身份证号的员工信息
select * from emp where idcard is not null;



3.查询年龄不等于88的员工信息
select * from emp where age != 88;
select* from emp where age < > 88;

select* from emp where age > 15 && age < 20;
select* from emp where age > 15 and age < 20;
select* from emp where age between 15 and 20;
三者等价


4.查询性别为女且年龄小于25岁的员工信息
select * from emp where gender = '女' and age < 25;

5.查询年龄等于18或20或40的员工信息
select * from emp where age = 18 or age = 20 or age = 40;
select * from emp where age in(18, 20, 40);

6.查询姓名为两个字的员工信息 
select * from emp where name like '__'  （两个下划线代表两个占位）

7.查询身份证号最后一位是X的员工信息
select * from emp where idcard like '%X';




聚合函数的用法： SELECT聚合函数(字段列表)FROM表名;
所有的null不参与聚合函数的运算

--1.统计该企业员工数量
select count(*)from emp;


--2.统计该企业员工的平均年龄
select avg(age)from emp;            max用于最大 min最小 sum求和



DQL - 分组查询
语法
SELECT字段列表FROM表名[WHERE条件]GROUP BY分组字段名[HAVING分组后过滤条件];

1.根据性别分组,
统计男性员工和女性员工的数量
select gender, count(*)from emp group by gender;

2查询年龄小于45的员工, 并根据工作地址分组, 获取员工的工作地址
select workaddress, count(*)from emp where age < 45 group by workaddress


查询年龄小于45的员工, 并根据工作地址分组, 获取员工数量大于等于3的工作地址
select workaddress, count(*)from emp where age < 45 group by workaddress having count(*) >= 3;

使用别名:
select workaddress, count(*)address_count from emp where age < 45 group by workaddress having address_count >= 3;


执行顺序:where > 聚合函数 > having


		

排序查询
SELECT字段列表FROM表名ORDER BY字段1排序方式1, 字段2排序方式2;
排序方式
ASC:升序(默认值)
DESC : 降序

注意 : 如果是多字段排序, 当第一个字段值相同时, 才会根据第二个字段进行排序。




1.根据年龄对公可的员工进行升序排序
select * from emp order by age asc;  asc可省略


2.根据年龄对公司的员工进行升序排序, 年龄相同, 再按照入职时间进行降序排序
select* from emp order by age asc, entrydate desc;




DQL - 分页查询
1.
语法
SELECT字段列表FROM表名LIMT起始索引, 查询记录数;




1.查询第1页员工数据, 每页展示10条记录
select* from emp limit 0, 10;
select* from emp limit 10;



2.查询第2页员工数据, 每页展示10条记录   -------- > (页码 - 1)* 页展示记录数
select* from emp limit 10, 10;




3.查询性别为男, 且年龄在20 - 40岁(含)以内的前5个员工信息, 对查询的结果按年龄升序排序, 年龄相同按入职时间升序排序。
select* from emp where gender = '男' and age between 20 and 40 order by age asc, entrydate asc limit 5;


















