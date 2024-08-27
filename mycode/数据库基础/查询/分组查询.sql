

分组查询：

1.根据性别分组,
统计男性员工和女性员工的数量
select gender, count(*)from emp group by gender;
2查询年龄小于45的员工数量, 并根据工作地址分组, 获取员工的工作地址
select workaddress, count(*)from emp where age < 45 group by workaddress


查询年龄小于45的员工数量, 并根据工作地址分组, 获取员工数量大于等于3的工作地址
select workaddress, count(*)from emp where age < 45 group by workaddress having count(*) >= 3;




