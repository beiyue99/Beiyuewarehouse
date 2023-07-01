




1.在创建表时, 指定存储引擎
CREATE TABLE表名(
	字段1 字段1类型「COMMENT 字段1注释],
	字段n 字段n类型[COMMENT 字段n注释]
)ENGINE = INNODB[COMMENT表注释]



创建表my_memory, 指定Memory存储引擎
create table my_memory(
	id int,
	name varchar(10)
)
engine Memory;







>InnoDB:是Mysql的默认存储引擎, 支持事务、外键。如果应用对事务的完整性有比较高的要求, 在并发条件下要求数据的一致
性, 数据操作除了插入和查询之外, 还包含很多的更新、删除操作, 那么InnoDB存储引擎是比较合适的选择。
>MyISAM公如果应用是以读操作和插入操作为主, 只有很少的更新和删除操作, 并且对事务的完整性、并发性要求不是很高, 那
么选择这个存储引擎是非常合适的。
> MEMORY:将所有数据保存在内存中, 访问速度快, 通常用于临时表及缓存。MEMORYE的缺陷就是对表的大小有限制, 太大的表
无法缓存在内存中, 而且无法保障数据的安全性。












































