
#对于union:查询, 就是把多次查询的结果合并起来, 形成一个新的查询结果集。

--1.将薪资低于5000的员工, 和年龄大于50岁的员工全部查询出来.
select* from emp where salary > 5000 union all select * from emp where age > 50;
#不省略all会有重复数据
select* from emp where salary > 5000 union     select * from emp where age > 50;  

select* from emp where salary > 5000 or age > 50;
select distinct* from emp where salary > 5000 or age > 50;  #这样就不会有重复数据

