


非空约束
限制该字段的数据不能为null
NOT NULL

唯一约束
保证该字段的所有数据都是唯一、不重复的
UNIQUE

主键约束
主键是一行数据的唯一标识, 要求非空且唯一
PRIMARY KEY

默认约束
保存数据时, 如果未指定该字段的值, 则采用默认值
DEFAULT

检查约束(8.0.16版本之后)
保证字段值满足某一个条件
CHECK

外键约束
用来让两张表的数据之间建立连接, 保证数据的一致性和完整性
FOREIGN KEY

CREATE TABLE t_emp(
	id INT PRIMARY KEY,
	name VARCHAR(22),
	sex VARCHAR(2) DEFAULT '男'
) DEFAULT CHARSET = utf8;

如果是添加字符串型默认值要使用单引号，如果是整型则不需要加任何符号；
如果要添加的是中文默认值，则需要加上DEFAULT CHARSET = utf8; 使用英文字符则不需要。


id				  	   name					   age							  status						gender
ID唯一标识		  	   姓名					   年龄						      状态							性别
int				       varchar(10)				int							  char(1)					    char(1)
主键, 并且自动增长     不为空, 并且唯一        大于0, 并且小于等于120        如果没有指定该值, 默认为1      无


  
create table user(
	id int primary key auto_increment comment'主键',
	name varchar(10)not null unique comment'姓名',
	age int check(age > 0 && age <= 120)comment'年龄',
	status char(1)default'1'comment'状态',
	gender char(1)comment'性别'
	comment'用户表':



插入数据时不用插入主键，它是系统默认的从1开始自增
当已经有tom的时候，再插入tom，插入不成功，但是主键已经被申请了
当插入null时，主键不会被申请




>添加外键
CREATE TABLE表名(
	字段名
	数据类型
	[CONSTRAINT] [外键名称] FOREIGN KEY(外键字段名)REFERENCES 主表(主表列名);


ALTER TABLE表名ADD CONSTRAINT外键名称FOREIGN KEY(外键字段名)REFERENCES主表(主表列名);

alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id);    
给emp表添加外键，键为dept表的id
fk_emp_dept_id  是个外键名称 ，可以自定义


有个学生表，有个课程表，现在创建第三个表，将他们俩关联起来
create table student_course(
	id int auto_increment comment 'primary key,
	studentid int not null comment'学生ID',
	courseid int not null comment'课程ID',
	constraint fk_courseid foreign key(courseid)references course(id),     courseid关联的是课程表的主键
	constraint fk_studentid foreign key(studentid)references student(id)   studentid关联的是学生表的主键
)comment'学生课程中间表;

insert into student_course values(null, 1, 1), (null, 1, 2), (null, 1, 3), (null, 2, 2), (null, 2, 3), (null, 3, 4);









>删除外键
ALTER TABLE表名DROP FOREIGN KEY外键名称;
alter table emp drop foreign key fk_emp_dept_id; 








NO ACTION
当在父表中删除 / 更新对应记录时, 首先检查该记录是否有对应外键, 如果有则不允许删除 / 更新。(与RESTRICT一致)
RESTRICT
当在父表中删除 / 更新对应记录时, 首先检查该记录是否有对应外键, 如果有则不允许删除 / 更新。(与NO ACTION一致)
CASCADE
当在父表中删除 / 更新对应记录时, 首先检查该记录是否有对应外键, 如果有, 则也删除更新外键在子表中的记录。
SET NULL
当在父表中删除对应记录时, 首先检查该记录是否有对应外键, 如果有则设置子表中该外键值为ull(这就要求该外键允许取null)。
SET DEFAULT
父表有变更时, 子表将外键列设置成一个默认的值(Innodb不支持)



CASCADE：   如果父表id删除了，那么子表也会跟着删除，父表更新了，子表也跟着更新
ALTER TABLE表名ADD CONSTRAINT外键名称FOREIGN KEY(外键字段)REFERENCES主表名(主表字段名)ON UPDATE CASCADE ON DELETE CASCADE;
alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id)on update cascade on delete cascade;


SET NULL：
alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id)on update set null on delete set null

























































