
>隐式内连接   #现在更推荐易读的显式连接
--1.查询每一个员工的姓名, 及关联的部门的名称(隐式内连接实现)
select e.name, d.name from emp e, dept d where e.dept_id = d.id;  #起别名之后，就不允许使用原名了



> 显式内连接   #返回两个表中满足连接条件的行。
--2.查询每一个员工的姓名, 及关联的部门的名称(显式内连接实现)-- - INNER J0IN, ··ON···
select e.name, d.name from emp e inner join dept d on e.dept_id = d.id;
select e.name, d.name from emp e join dept d on e.dept_id = d.id;  #JOIN 默认是 INNER JOIN




左外连接

--1.查询emp表的所有数据, 和对应的部门信息(左外连接)
select e.*, d.name from emp e left outer join dept d on e.dept_id = d.id;
select e.*, d.name from emp e left       join dept d on e.dept_id = d.id;



> 右外连接
--2.查询dept表的所有数据, 和对应的员工信息(右外连接)
select d.*, e.*from emp e right outer join dept d on e.dept_id = d.id;
select d.*, e.*from dept d left outer join emp e on e.dept_id = d.id;       
#可以看出左外也可以实现，所以一般用左外就行了




--2.查询所有员工emp及其领导的名字emp, 如果员工没有领导, 也需要查询出来
表结构 : empa, empb
select a.name'员工', b.name '领导' from emp a left join emp b on a.managerid = b.id;
