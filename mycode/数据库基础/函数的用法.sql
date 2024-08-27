CONCAT(S1, S2, ...Sn)
字符串拼接, 将S1, S2, Sn拼接成一个字符串            select concat('Hello', MySQL');
LOWER(str)
将字符串str全部转为小写                            select Lower('Hello');
UPPER(str)
将字符串str全部转为大写
LPAD(str, n, pad)                                
左填充, 用字符串pad对str的左边进行填充, 达到n个字符串长度       select lpad('01', 5, -')
RPAD(str, n, pad)
右填充, 用字符串pad对str的右边进行填充, 达到n个字符串长度 
TRIM(str)
去掉字符串头部和尾部的空格                            select trim('Hello MySQL )
SUBSTRING(str, start, len) 
返回从字符串str从start位置起的len个长度的字符串      select substring('Hello MySQL', 1, 5); 没有第零个位置



1.由于业务需求变更, 企业员工的工号, 统一5位数, 目前不足5位数的全部在前面补0。比如:1号员工的工号应该为00001。
update emp set workno = lpad(workno, 5, '0');






CEIL(x)
向上取整  select ceil(1.1);
FLOOR(x)
向下取整   select floor(1.9);
MOD(x, y)
返回x / y的模   select mod(3, 4);
RAND()
返回0~1内的随机数   select rand();
ROUND(x, y)
求参数x的四舍五入的值, 保留y位小数   select round(2.345, 2);



案例:通过数据库的函数, 生成一个六位数的随机验证码。
select round(rand() * 1000000, 0);
select lpad(round(rand() * 1000000, 0), 6, '0');   需要补零，不然有可能不足六位





CURDATE()
返回当前日期   select curdate();
CURTIME()
返回当前时间    select curtime();
NOW()
返回当前日期和时间
YEAR(date)
获取指定date的年份
MONTH(date)
获取指定date的月份
DAY(date)
获取指定date的日期 

select YEAR(now());
select MONTH(now());
select DAY(now());




DATE ADD(date, INTERVAL expr type)
返回一个日期 / 时间值加上一个时间间隔eXpr后的时间值

select date_add(now(), INTERVAL 76 DAY); 当前时间往后70天


DATEDIFF(date1, date2)
返回起始时间date1和结束时间date2之间的天数

se1ect datediff('2021-12-01', '2021-11-01');






案例:查询所有员工的入职天数, 并根据入职天数倒序排序。
select name, datediff(curdate(), entrydate)from emp;


select name, datediff(curdate(), entrydate)as 'entrydays'from emp order by entrydays desc;






IF(value, t, f)
如果value:为true, 则返回t, 否则返回f    select if (false, 'Ok', 'Error');
IFNULL(valye1, value2)
如果value1不为空, 返回value1, 否则返回value2   select ifnull(null, 'Default');
CASE WHEN[val1] THEN[res1]...ELSE[default] END
如果vall为true, 返回res1, .否则返回default默认值
CASE[expr] WHEN[val1] THEN[res1]...ELSE[default] END
如果expr的值等于vall, 返回res1, .否则返回default默认值



需求:查询mp表的员工姓名和工作地址
(北京 / 上海---- > 一线城市, 其他---- > 二线城市)
select name, (case workaddress when'北京'then'一线城市'when'上海'then'二线城市'eLse'二线城市'end)as'工作地址' from emp;







select
id,
name,
(case when math >= 85then'优秀'when math >= 60then'及格'else'不及格'end)'数学',
(case when english >= 85then'优秀'when english >= 60then'及格'eLse'不及格'end)'英语',
(case when chinese >= 85then'优秀'when chinese >= 60then'及格'else'不及格'end)'语文' from score;





























