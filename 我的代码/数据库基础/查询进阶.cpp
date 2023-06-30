多表查询--笛卡尔积
select from emp, dept where emp.dept_id = dept.id;





>隐式内连接
SELECT字段列表FROM表1, 表2 WHERE条件;
--1.查询每一个员工的姓名, 及关联的部门的名称(隐式内连接实现)
--表结构:emp, dept
--连接条件 : emp.dept_id = dept.id
select emp.name, dept.name from emp, dept where emp.dept_id = dept.id

select e.name, d.name from emp e, dept d where e.dept_id = d.id;     起别名之后，就不允许使用原名了



> 显式内连接
SELECT字段列表FROM表1[INNER]JOIN表2 ON连接条件
--2.查询每一个员工的姓名, 及关联的部门的名称(显式内连接实现)-- - INNER J0IN, ··ON···
--表结构:emp, dept
--连接条件 : emp.dept_id = dept.id
select e.name, d.name from emp e inner join dept d on e.dept_id = d.id;
select e.name, d.name from emp e join dept d on e.dept_id = d.id;








左外连接
SELECT字段列表FROM表1LEFT[OUTER]JOIN表2 ON条件.
相当于查询表1(左表)的所有数据包含表1和表2交集部分的数据

--1.查询emp表的所有数据, 和对应的部门信息(左外连接)
--表结构:emp, dept
--连接条件 : emp.dept id = dept.id
select e.*, d.name from emp e left outer join dept d on e.dept_id = d.id;
select e.*, d.name from emp e left join dept d on e.dept_id = d.id;




> 右外连接
SELECT字段列表FROM表1 RIGHT[OUTER]JOIN表2 ON条件.
相当于查询表2(右表)的所有数据包含表1和表2交集部分的数据
--2.查询dept表的所有数据, 和对应的员工信息(右外连接)
select d.*, e.*from emp e right outer join dept d on e.dept_id = d.id;
select d.*, e.*from dept d left outer join emp e on e.dept_id = d.id;       可以看出左外也可以实现，所以一般用左外就行了






自连接查询语法:
SELECT字段列表FROM表A别名A JOIN表A别名B ON条件...;
自连接查询, 可以是内连接查询, 也可以是外连接查询。


- 自连接
--1.查询员工及其所属领导的名字
--表结构:emp
select a.name, b.name from emp a, emp b where a.managerid = b.id;

--2.查询所有员工emp及其领导的名字emp, 如果员工没有领导, 也需要查询出来
表结构 : empa, empb
select a.name'员工', b.name '领导' from emp a left join emp b on a.managerid = b.id;






对于union:查询, 就是把多次查询的结果合并起来, 形成一个新的查询结果集。
SELECT字段列表FROM表A.
UNION[ALL]
SELECT字段列表FROM表B

- union all, union
--1.将薪资低于5000的员工, 和年龄大于50岁的员工全部查询出来.
select* from emp where salary > 5000 union all select * from emp where age > 50;
select* from emp where salary > 5000 union select* from emp where age > 50;  这样就不会有重复数据

select* from emp where salary > 5000 or age > 50;
select distinct* from emp where salary > 5000 or age > 50;  这样就不会有重复数据


对于联合查询的多张表的列数必须保持一致, 字段类型也需要保持一致。







概念:SQL语句中嵌套SELECT语句, 称为嵌套查询, 又称子查询。
SELECT* FROM t1 WHERE column1 = (SELECT column1 FROM t2);




标量子查询
--1.查询"销售部”的所有员工信息
a.查询"销售部"部门ID
select id from dept where name = '销售部';
--b.根据销售部部门ID, 查询员工信息
select* from emp where dept_id = 4;


select* from emp where dept.id = (select id from dept where name = '销售部')







--2.查询在"方东白”入职之后的员工信息
--a.查询方东白的入职日期
select entrydate from emp where name = '方东白';
--b.查询指定入职日期之后入职的员工信息
select* from emp where entrydate > (select entrydate from emp where name = '方东白');









--列子查询
--1.查询"销售部”和”市场部”的所有员工信息
--a.查询"销售部”和"市场部"的部门ID
select id from dept where name = '销售部' or name = '市场部';
--b.根据部1门ID, 查询员工信息
select* from emp where dept_id in(2, 4);


select* from emp where dept_id in(select id from dept where name = '销售部' or name = '市场部');





--2.查询比财务部所有人工资都高的员工信息
--a.查询所有财务部人员工资
select salary from emp where dept_id = (select id from dept where name = '财务部');
--b.比财务部所有人工资都高的员工信息
select* from emp where salary > all(select salary from emp where dept_id = (select id from dept where name = '财务部'))

any表示任一   all表示所有  some和any一样，两者完全等价







行子查询
--1.查询与"张无忌”的薪资及直属领导相同的员工信息;
--a.查询"张无忌”的薪资及直属领导
select salary, managerid from emp where name = '张无忌';
--b.查询与“张无忌”的薪资及直属领导相同的员工信息;
select* from emp where(salary, managerid) = (select salary, managerid from emp where name = '张无忌')





--表子查询
- 1.查询与"鹿杖客”,“宋远桥”的职位和薪资相同的员工信息
--a.查询"鹿杖客”,"宋远桥”的职位和薪资
select job, salary from emp where name = '鹿杖客' or name = '宋远桥';
--b.查询与”鹿杖客”, “宋远桥”的职位和薪资相同的员工信息
select* from emp where(job, salary)in(select job, salary from emp where name = '鹿杖客' or name = '宋远桥');



--2.查询入职日期是"2006-01-01”之后的员工信息,及其部门信息
--a.入职日期是"2006-01-01"之后的员工信息
select * from emp where entrydate > '2006-01-01';
--b.查询这部分员工, 对应的部门信息:
select e.*, d.*from(select* from emp where entrydate > '2006-01-01')e left join dept d on e.dept_id = d.id





// 案例:


--1., 查询员工的姓名、年龄、职位、部门信息(隐式内连接)
--表:emp, dept
连接条件 : emp.dept_id = dept.id
select e.name, e.age, e.job, d.name from emp e, dept d where e.dept_id = d.id;
--2.查询年龄小于30岁的员工的姓名、年龄、职位、部门信息(显式内连接)
--表:emp, dept
--连接条件 : emp.dept_id = dept.id
select e.name, e.age, e.job, d.name from emp e inner join dept d on e.dept_id = d.id where e.age < 30;
--3.查询拥有员工的部门ID、部门名称
表 : emp, dept
--连接条件 : emp.dept_id = dept.id
select distinct d.id, d.name from emp e, dept d where e.dept_id = d.id;
--4.查询所有年龄大于40岁的员工, 及其归属的部门名称:如果员工没有分配部门, 也需要展示出来
表 : emp, dept
--连接条件 : emp.dept_id = dept.id
外连接
select e.*, d.name from emp e left join dept d on e.dept_id = d.id where e.age > 40
--5.查询所有员工的工资等级
表 : emp, salgrade
连接条件 : emp.salary >= salgrade.losal and emp.salary <= salgrade.hisal
select e.*, s.grade from emp e, salgrade s where e.salary >= s.losal and e.salary <= s.hisal;
--6.查询"研发部”所有员工的信息及工资等级
表:emp, salgrade, dept
连接条件 : emp.salary between salgrade.losaland salgrade.hisal, emp.dept_id = dept.id
- 查询条件 : dept.name = '研发部'
select e.*, s.grade from emp e, dept d, salgrade s where e.dept_id = d.id and (e.salary between s.Losal and s.hisal) and d.name = '研发部'
--7.查询"研发部”员工的平均工资
--表 : emp, dept
--连接条件 :
	emp.dept_id = dept.id
	select avg(e.salary)from emp e, dept d where e.dept_id = d.id and d.name = '研发部';
--8.查询工资比"灭绝”高的员工信息。
--
a.查询”灭绝”的薪资
b, 查询比她工资高的员工数据
select* from emp where salary > (select salary from emp where name = '灭绝');
--10.查询低于本部门平均工资的员工信息
--a.查询指定部门平均薪资
select avg(e1.salary)from emp el where el.dept_id = 1;
select avg(e1.salary)from emp el where e1.dept_id = 2;
--b.查询低于本部门平均工资的员工信息
select* from emp e2 where e2.salary < select avg(e1.salary)from emp e1 where e1.dept_id = e2.dept_id);
11.查询所有的部门信息, 并统计部门的员工人数
select d.id, d.name, (select count(*)from emp e where e.dept_id = d.id)'人数'from dept d;
select count(*)from emp where dept_id = 1;
12.查询所有学生的选课情况, 展示出学生名称, 学号, 课程名称
表 : student, course, student_course
连接条件 : student.id = student._course.studentid, course.id = student_course.courseid
select s.name, s.no, c.name from student s, student_course sc, course c where s.id = sc.studentid and sc.courseid = c.id
