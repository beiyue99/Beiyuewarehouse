查询
查询所有数据库
SHOW DATABASES;
查询当前数据库
SELECT DATABASE();

创建
CREATE DATABASE「IF NOT EXISTS]数据库名「DEFAULT CHARSET字符集]「COLLATE排序规则]:

删除
DROP DATABASE「IF EXISTS]数据库名;

使用
USE数据库名;




查询当前数据库所有表
SHOW TABLES;
查询表结构
DESC表名;
查询指定表的建表语句
SHOW CREATE TABLE表名;






DDL - 表操作 - 创建
CREATE TABLE表名(
	字段1字段1类型[COMMENT字段1注释],
	字段2字段2类型[COMMENT字段2注释],
	字段3字段3类型[COMMENT字段3注释],
	字段n字段n类型[COMMENT字段n注释]
)[COMMENT表注释];



age TINYINT UNSIGNED     表示age是个无符号整型
score double(4, 1)   表示score最大4个长度，如100.0   小数点后面一位


































































































