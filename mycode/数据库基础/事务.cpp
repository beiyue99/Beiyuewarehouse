



--转账操作(张三给李四转账1000)
--1.查询张三账户余额
select * from account where name = '张三';
--2.将张三账户余额 - 1000
update account set money = money - 1000 where name = '张三';
--3.将季四账户余额 + 1000
update account set money = money + l000 where name = '李四';





查看 / 设置事务提交方式
SELECT @@autocommit
SET @@autocommit = 0;   //设置为手动提交    之后执行指令，必须要输入commit，如果出错，可以回滚
提交事务
COMMIT
回滚事务
ROLLBACK;




//不需要设置提交方式
开启事务
START TRANSACTION BEGIN
提交事务
COMMIT;                执行后，如果不提交，那么库的数据就不会变化
回滚事务
ROLLBACK;



脏读
一个事务读到另外一个事务还没有提交的数据。
不可重复读
一个事务先后读取同一条记录, 但两次读取的数据不同, 称之为不可重复读。   //当另一个终端commit一个指令后，当前终端再次查，就会出现不同
幻读
一个事务按照条件查询数据时, 没有对应的数据行, 但是在插入数据时, 又发现这行数据已经存在, 好像出现了”幻影”。



查看事务隔离级别
SELECT @@TRANSACTION_ISOLATION;
-设置事务隔离级别
SET[SESSION | GLOBAL] TRANSACTION ISOLATION LEVEL{ READ UNCOMMITTED | READ COMMITTED | REPEATABLE READ | SERIALIZABLE }
//最后一个只允许进行一个事务，因此，不会出现幻读。
















































