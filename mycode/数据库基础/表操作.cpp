
添加字段
ALTER TABLE表名ADD字段名类型(长度)「COMMENT注释][约束]:




+-----------+------------------+------+-----+---------+-------+
| Field     | Type             | Null | Key | Default | Extra |
+-----------+------------------+------+-----+---------+-------+
| id        | int              | YES  |     | NULL    |       |
| workno    | varchar(10)      | YES  |     | NULL    |       |
| name      | varchar(10)      | YES  |     | NULL    |       |
| gender    | char(1)          | YES  |     | NULL    |       |
| age       | tinyint unsigned | YES  |     | NULL    |       |
| idcard    | char(18)         | YES  |     | NULL    |       |
| entrydate | date             | YES  |     | NULL    |       |
+-----------+------------------+------+-----+---------+-------+

为emp表增加一个新的字段”昵称”为nickname, 类型为varchar(2O)

alter table emp add nickname varchar(20)comment'昵称';




修改数据类型
ALTER TABLE表名MODIFY字段名新数据类型(长度);

修改字段名和字段类型
ALTER TABLE表名CHANGE 旧字段名 新字段名 类型(长度)[COMMENT注释][约束];



将emp表的nickname:字段修改为username, 类型为varchar(30)

alter table emp change nickname username varchar(30)comment'用户名';



删除字段
ALTER TABLE 表名 DROP字段名;



将emp表的字段username删除
alter table emp drop username;



修改表名
ALTER TABLE 表名 RENAME TO 新表名;





删除表
DROP TABLE[IF EXISTS]表名;
删除指定表, 并重新创建该表
TRUNCATE TABLE 表名;






添加数据(INSERT)
修改数据(UPDATE)
删除数据(DELETE)

给指定字段添加数据
INSERT INTO表名(字段名1, 字段名2, )VALUES(值1, 值2...);
给全部字段添加数据
INSERT INTO表名VALUES(值1, 值2, );


修改数据
UPDATE 表名 SET 字段名1 = 值1, 字段名2 = 值2, [HERE条件];


删除数据
DELETE FROM表名[WHERE条件]

DELETE语句不能删除某一个字段的值(可以使用UPDATE)。




















































