����ѯ--�ѿ�����
select from emp, dept where emp.dept_id = dept.id;





>��ʽ������
SELECT�ֶ��б�FROM��1, ��2 WHERE����;
--1.��ѯÿһ��Ա��������, �������Ĳ��ŵ�����(��ʽ������ʵ��)
--��ṹ:emp, dept
--�������� : emp.dept_id = dept.id
select emp.name, dept.name from emp, dept where emp.dept_id = dept.id

select e.name, d.name from emp e, dept d where e.dept_id = d.id;     �����֮�󣬾Ͳ�����ʹ��ԭ����



> ��ʽ������
SELECT�ֶ��б�FROM��1[INNER]JOIN��2 ON��������
--2.��ѯÿһ��Ա��������, �������Ĳ��ŵ�����(��ʽ������ʵ��)-- - INNER J0IN, ����ON������
--��ṹ:emp, dept
--�������� : emp.dept_id = dept.id
select e.name, d.name from emp e inner join dept d on e.dept_id = d.id;
select e.name, d.name from emp e join dept d on e.dept_id = d.id;








��������
SELECT�ֶ��б�FROM��1LEFT[OUTER]JOIN��2 ON����.
�൱�ڲ�ѯ��1(���)���������ݰ�����1�ͱ�2�������ֵ�����

--1.��ѯemp�����������, �Ͷ�Ӧ�Ĳ�����Ϣ(��������)
--��ṹ:emp, dept
--�������� : emp.dept id = dept.id
select e.*, d.name from emp e left outer join dept d on e.dept_id = d.id;
select e.*, d.name from emp e left join dept d on e.dept_id = d.id;




> ��������
SELECT�ֶ��б�FROM��1 RIGHT[OUTER]JOIN��2 ON����.
�൱�ڲ�ѯ��2(�ұ�)���������ݰ�����1�ͱ�2�������ֵ�����
--2.��ѯdept�����������, �Ͷ�Ӧ��Ա����Ϣ(��������)
select d.*, e.*from emp e right outer join dept d on e.dept_id = d.id;
select d.*, e.*from dept d left outer join emp e on e.dept_id = d.id;       ���Կ�������Ҳ����ʵ�֣�����һ�������������






�����Ӳ�ѯ�﷨:
SELECT�ֶ��б�FROM��A����A JOIN��A����B ON����...;
�����Ӳ�ѯ, �����������Ӳ�ѯ, Ҳ�����������Ӳ�ѯ��


- ������
--1.��ѯԱ�����������쵼������
--��ṹ:emp
select a.name, b.name from emp a, emp b where a.managerid = b.id;

--2.��ѯ����Ա��emp�����쵼������emp, ���Ա��û���쵼, Ҳ��Ҫ��ѯ����
��ṹ : empa, empb
select a.name'Ա��', b.name '�쵼' from emp a left join emp b on a.managerid = b.id;






����union:��ѯ, ���ǰѶ�β�ѯ�Ľ���ϲ�����, �γ�һ���µĲ�ѯ�������
SELECT�ֶ��б�FROM��A.
UNION[ALL]
SELECT�ֶ��б�FROM��B

- union all, union
--1.��н�ʵ���5000��Ա��, ���������50���Ա��ȫ����ѯ����.
select* from emp where salary > 5000 union all select * from emp where age > 50;
select* from emp where salary > 5000 union select* from emp where age > 50;  �����Ͳ������ظ�����

select* from emp where salary > 5000 or age > 50;
select distinct* from emp where salary > 5000 or age > 50;  �����Ͳ������ظ�����


�������ϲ�ѯ�Ķ��ű���������뱣��һ��, �ֶ�����Ҳ��Ҫ����һ�¡�







����:SQL�����Ƕ��SELECT���, ��ΪǶ�ײ�ѯ, �ֳ��Ӳ�ѯ��
SELECT* FROM t1 WHERE column1 = (SELECT column1 FROM t2);




�����Ӳ�ѯ
--1.��ѯ"���۲���������Ա����Ϣ
a.��ѯ"���۲�"����ID
select id from dept where name = '���۲�';
--b.�������۲�����ID, ��ѯԱ����Ϣ
select* from emp where dept_id = 4;


select* from emp where dept.id = (select id from dept where name = '���۲�')







--2.��ѯ��"�����ס���ְ֮���Ա����Ϣ
--a.��ѯ�����׵���ְ����
select entrydate from emp where name = '������';
--b.��ѯָ����ְ����֮����ְ��Ա����Ϣ
select* from emp where entrydate > (select entrydate from emp where name = '������');









--���Ӳ�ѯ
--1.��ѯ"���۲����͡��г�����������Ա����Ϣ
--a.��ѯ"���۲�����"�г���"�Ĳ���ID
select id from dept where name = '���۲�' or name = '�г���';
--b.���ݲ�1��ID, ��ѯԱ����Ϣ
select* from emp where dept_id in(2, 4);


select* from emp where dept_id in(select id from dept where name = '���۲�' or name = '�г���');





--2.��ѯ�Ȳ��������˹��ʶ��ߵ�Ա����Ϣ
--a.��ѯ���в�����Ա����
select salary from emp where dept_id = (select id from dept where name = '����');
--b.�Ȳ��������˹��ʶ��ߵ�Ա����Ϣ
select* from emp where salary > all(select salary from emp where dept_id = (select id from dept where name = '����'))

any��ʾ��һ   all��ʾ����  some��anyһ����������ȫ�ȼ�







���Ӳ�ѯ
--1.��ѯ��"���޼ɡ���н�ʼ�ֱ���쵼��ͬ��Ա����Ϣ;
--a.��ѯ"���޼ɡ���н�ʼ�ֱ���쵼
select salary, managerid from emp where name = '���޼�';
--b.��ѯ�롰���޼ɡ���н�ʼ�ֱ���쵼��ͬ��Ա����Ϣ;
select* from emp where(salary, managerid) = (select salary, managerid from emp where name = '���޼�')





--���Ӳ�ѯ
- 1.��ѯ��"¹�ȿ͡�,����Զ�š���ְλ��н����ͬ��Ա����Ϣ
--a.��ѯ"¹�ȿ͡�,"��Զ�š���ְλ��н��
select job, salary from emp where name = '¹�ȿ�' or name = '��Զ��';
--b.��ѯ�롱¹�ȿ͡�, ����Զ�š���ְλ��н����ͬ��Ա����Ϣ
select* from emp where(job, salary)in(select job, salary from emp where name = '¹�ȿ�' or name = '��Զ��');



--2.��ѯ��ְ������"2006-01-01��֮���Ա����Ϣ,���䲿����Ϣ
--a.��ְ������"2006-01-01"֮���Ա����Ϣ
select * from emp where entrydate > '2006-01-01';
--b.��ѯ�ⲿ��Ա��, ��Ӧ�Ĳ�����Ϣ:
select e.*, d.*from(select* from emp where entrydate > '2006-01-01')e left join dept d on e.dept_id = d.id





// ����:


--1., ��ѯԱ�������������䡢ְλ��������Ϣ(��ʽ������)
--��:emp, dept
�������� : emp.dept_id = dept.id
select e.name, e.age, e.job, d.name from emp e, dept d where e.dept_id = d.id;
--2.��ѯ����С��30���Ա�������������䡢ְλ��������Ϣ(��ʽ������)
--��:emp, dept
--�������� : emp.dept_id = dept.id
select e.name, e.age, e.job, d.name from emp e inner join dept d on e.dept_id = d.id where e.age < 30;
--3.��ѯӵ��Ա���Ĳ���ID����������
�� : emp, dept
--�������� : emp.dept_id = dept.id
select distinct d.id, d.name from emp e, dept d where e.dept_id = d.id;
--4.��ѯ�����������40���Ա��, ��������Ĳ�������:���Ա��û�з��䲿��, Ҳ��Ҫչʾ����
�� : emp, dept
--�������� : emp.dept_id = dept.id
������
select e.*, d.name from emp e left join dept d on e.dept_id = d.id where e.age > 40
--5.��ѯ����Ա���Ĺ��ʵȼ�
�� : emp, salgrade
�������� : emp.salary >= salgrade.losal and emp.salary <= salgrade.hisal
select e.*, s.grade from emp e, salgrade s where e.salary >= s.losal and e.salary <= s.hisal;
--6.��ѯ"�з���������Ա������Ϣ�����ʵȼ�
��:emp, salgrade, dept
�������� : emp.salary between salgrade.losaland salgrade.hisal, emp.dept_id = dept.id
- ��ѯ���� : dept.name = '�з���'
select e.*, s.grade from emp e, dept d, salgrade s where e.dept_id = d.id and (e.salary between s.Losal and s.hisal) and d.name = '�з���'
--7.��ѯ"�з�����Ա����ƽ������
--�� : emp, dept
--�������� :
	emp.dept_id = dept.id
	select avg(e.salary)from emp e, dept d where e.dept_id = d.id and d.name = '�з���';
--8.��ѯ���ʱ�"������ߵ�Ա����Ϣ��
--
a.��ѯ���������н��
b, ��ѯ�������ʸߵ�Ա������
select* from emp where salary > (select salary from emp where name = '���');
--10.��ѯ���ڱ�����ƽ�����ʵ�Ա����Ϣ
--a.��ѯָ������ƽ��н��
select avg(e1.salary)from emp el where el.dept_id = 1;
select avg(e1.salary)from emp el where e1.dept_id = 2;
--b.��ѯ���ڱ�����ƽ�����ʵ�Ա����Ϣ
select* from emp e2 where e2.salary < select avg(e1.salary)from emp e1 where e1.dept_id = e2.dept_id);
11.��ѯ���еĲ�����Ϣ, ��ͳ�Ʋ��ŵ�Ա������
select d.id, d.name, (select count(*)from emp e where e.dept_id = d.id)'����'from dept d;
select count(*)from emp where dept_id = 1;
12.��ѯ����ѧ����ѡ�����, չʾ��ѧ������, ѧ��, �γ�����
�� : student, course, student_course
�������� : student.id = student._course.studentid, course.id = student_course.courseid
select s.name, s.no, c.name from student s, student_course sc, course c where s.id = sc.studentid and sc.courseid = c.id
