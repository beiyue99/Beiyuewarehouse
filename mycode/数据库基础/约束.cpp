


�ǿ�Լ��
���Ƹ��ֶε����ݲ���Ϊnull
NOT NULL

ΨһԼ��
��֤���ֶε��������ݶ���Ψһ�����ظ���
UNIQUE

����Լ��
������һ�����ݵ�Ψһ��ʶ, Ҫ��ǿ���Ψһ
PRIMARY KEY

Ĭ��Լ��
��������ʱ, ���δָ�����ֶε�ֵ, �����Ĭ��ֵ
DEFAULT

���Լ��(8.0.16�汾֮��)
��֤�ֶ�ֵ����ĳһ������
CHECK

���Լ��
���������ű������֮�佨������, ��֤���ݵ�һ���Ժ�������
FOREIGN KEY

CREATE TABLE t_emp(
	id INT PRIMARY KEY,
	name VARCHAR(22),
	sex VARCHAR(2) DEFAULT '��'
) DEFAULT CHARSET = utf8;

���������ַ�����Ĭ��ֵҪʹ�õ����ţ��������������Ҫ���κη��ţ�
���Ҫ��ӵ�������Ĭ��ֵ������Ҫ����DEFAULT CHARSET = utf8; ʹ��Ӣ���ַ�����Ҫ��


id				  	   name					   age							  status						gender
IDΨһ��ʶ		  	   ����					   ����						      ״̬							�Ա�
int				       varchar(10)				int							  char(1)					    char(1)
����, �����Զ�����     ��Ϊ��, ����Ψһ        ����0, ����С�ڵ���120        ���û��ָ����ֵ, Ĭ��Ϊ1      ��


  
create table user(
	id int primary key auto_increment comment'����',
	name varchar(10)not null unique comment'����',
	age int check(age > 0 && age <= 120)comment'����',
	status char(1)default'1'comment'״̬',
	gender char(1)comment'�Ա�'
	comment'�û���':



��������ʱ���ò�������������ϵͳĬ�ϵĴ�1��ʼ����
���Ѿ���tom��ʱ���ٲ���tom�����벻�ɹ������������Ѿ���������
������nullʱ���������ᱻ����




>������
CREATE TABLE����(
	�ֶ���
	��������
	[CONSTRAINT] [�������] FOREIGN KEY(����ֶ���)REFERENCES ����(��������);


ALTER TABLE����ADD CONSTRAINT�������FOREIGN KEY(����ֶ���)REFERENCES����(��������);

alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id);    
��emp������������Ϊdept���id
fk_emp_dept_id  �Ǹ�������� �������Զ���


�и�ѧ�����и��γ̱����ڴ���������������������������
create table student_course(
	id int auto_increment comment 'primary key,
	studentid int not null comment'ѧ��ID',
	courseid int not null comment'�γ�ID',
	constraint fk_courseid foreign key(courseid)references course(id),     courseid�������ǿγ̱������
	constraint fk_studentid foreign key(studentid)references student(id)   studentid��������ѧ���������
)comment'ѧ���γ��м��;

insert into student_course values(null, 1, 1), (null, 1, 2), (null, 1, 3), (null, 2, 2), (null, 2, 3), (null, 3, 4);









>ɾ�����
ALTER TABLE����DROP FOREIGN KEY�������;
alter table emp drop foreign key fk_emp_dept_id; 








NO ACTION
���ڸ�����ɾ�� / ���¶�Ӧ��¼ʱ, ���ȼ��ü�¼�Ƿ��ж�Ӧ���, �����������ɾ�� / ���¡�(��RESTRICTһ��)
RESTRICT
���ڸ�����ɾ�� / ���¶�Ӧ��¼ʱ, ���ȼ��ü�¼�Ƿ��ж�Ӧ���, �����������ɾ�� / ���¡�(��NO ACTIONһ��)
CASCADE
���ڸ�����ɾ�� / ���¶�Ӧ��¼ʱ, ���ȼ��ü�¼�Ƿ��ж�Ӧ���, �����, ��Ҳɾ������������ӱ��еļ�¼��
SET NULL
���ڸ�����ɾ����Ӧ��¼ʱ, ���ȼ��ü�¼�Ƿ��ж�Ӧ���, ������������ӱ��и����ֵΪull(���Ҫ����������ȡnull)��
SET DEFAULT
�����б��ʱ, �ӱ���������ó�һ��Ĭ�ϵ�ֵ(Innodb��֧��)



CASCADE��   �������idɾ���ˣ���ô�ӱ�Ҳ�����ɾ������������ˣ��ӱ�Ҳ���Ÿ���
ALTER TABLE����ADD CONSTRAINT�������FOREIGN KEY(����ֶ�)REFERENCES������(�����ֶ���)ON UPDATE CASCADE ON DELETE CASCADE;
alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id)on update cascade on delete cascade;


SET NULL��
alter table emp add constraint fk_emp_dept_id foreign key(dept_id)references dept(id)on update set null on delete set null

























































