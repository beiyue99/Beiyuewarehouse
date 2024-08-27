


--1.查询"销售部”的所有员工信息 
select* from emp where dept.id = (select id from dept where name = '销售部')



--2.查询在"方东白”入职之后的员工信息
select * from emp where entrydate > (select entrydate from emp where name = '方东白');







--2.查询比财务部所有人工资都高的员工信息
--a.查询所有财务部人员工资
select salary from emp where dept_id = (select id from dept where name = '财务部');
--b.比财务部所有人工资都高的员工信息
select * from emp where salary > 
all(select salary from emp where dept_id = (select id from dept where name = '财务部'))
#any表示任一   all表示所有  some和any一样，两者完全等价





--1.查询与"张无忌”的薪资及直属领导相同的员工信息;

select* from emp where(salary, managerid) = (select salary, managerid from emp where name = '张无忌')





--b.查询与”鹿杖客”, “宋远桥”的职位和薪资相同的员工信息
select* from emp where(job, salary)in
(select job, salary from emp where name = '鹿杖客' or name = '宋远桥');



--2.查询入职日期是"2006-01-01”之后的员工信息,及其部门信息
select e.*, d.* from
(select* from emp where entrydate > '2006-01-01') e left join dept d on e.dept_id = d.id


