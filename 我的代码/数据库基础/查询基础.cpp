1.��ѯ����ֶ�
SELECT�ֶ�1, �ֶ�2, �ֶ�3..FROM����;
SELECT* FROM����;


2.���ñ���
SELECT�ֶ�1[AS����1], �ֶ�2[AS����2].FROM����;


3.ȥ���ظ���¼
SELECT DISTINCT�ֶ��б�FROM����;



select name, workno, age from emp;   �ͻ�ӱ���ֻ��������������
select from emp; �᷵�����ű�


select workaddress as'������ַ'from emp;   as����ʡ��

select distinct workaddress'������ַ'from emp;




������ѯ
1.�﷨
SELECT�ֶ��б�FROM����WHERE�����б�;

--1.��ѯ�������88��Ա��
select * from emp where age=88;


2 ��ѯ�����֤�ŵ�Ա����Ϣ
select * from emp where idcard is not null;



3.��ѯ���䲻����88��Ա����Ϣ
select * from emp where age != 88;
select* from emp where age < > 88;

select* from emp where age > 15 && age < 20;
select* from emp where age > 15 and age < 20;
select* from emp where age between 15 and 20;
���ߵȼ�


4.��ѯ�Ա�ΪŮ������С��25���Ա����Ϣ
select * from emp where gender = 'Ů' and age < 25;

5.��ѯ�������18��20��40��Ա����Ϣ
select * from emp where age = 18 or age = 20 or age = 40;
select * from emp where age in(18, 20, 40);

6.��ѯ����Ϊ�����ֵ�Ա����Ϣ 
select * from emp where name like '__'  �������»��ߴ�������ռλ��

7.��ѯ���֤�����һλ��X��Ա����Ϣ
select * from emp where idcard like '%X';




�ۺϺ������÷��� SELECT�ۺϺ���(�ֶ��б�)FROM����;
���е�null������ۺϺ���������

--1.ͳ�Ƹ���ҵԱ������
select count(*)from emp;


--2.ͳ�Ƹ���ҵԱ����ƽ������
select avg(age)from emp;            max������� min��С sum���



DQL - �����ѯ
�﷨
SELECT�ֶ��б�FROM����[WHERE����]GROUP BY�����ֶ���[HAVING������������];

1.�����Ա����,
ͳ������Ա����Ů��Ա��������
select gender, count(*)from emp group by gender;

2��ѯ����С��45��Ա��, �����ݹ�����ַ����, ��ȡԱ���Ĺ�����ַ
select workaddress, count(*)from emp where age < 45 group by workaddress


��ѯ����С��45��Ա��, �����ݹ�����ַ����, ��ȡԱ���������ڵ���3�Ĺ�����ַ
select workaddress, count(*)from emp where age < 45 group by workaddress having count(*) >= 3;

ʹ�ñ���:
select workaddress, count(*)address_count from emp where age < 45 group by workaddress having address_count >= 3;


ִ��˳��:where > �ۺϺ��� > having


		

�����ѯ
SELECT�ֶ��б�FROM����ORDER BY�ֶ�1����ʽ1, �ֶ�2����ʽ2;
����ʽ
ASC:����(Ĭ��ֵ)
DESC : ����

ע�� : ����Ƕ��ֶ�����, ����һ���ֶ�ֵ��ͬʱ, �Ż���ݵڶ����ֶν�������




1.��������Թ��ɵ�Ա��������������
select * from emp order by age asc;  asc��ʡ��


2.��������Թ�˾��Ա��������������, ������ͬ, �ٰ�����ְʱ����н�������
select* from emp order by age asc, entrydate desc;




DQL - ��ҳ��ѯ
1.
�﷨
SELECT�ֶ��б�FROM����LIMT��ʼ����, ��ѯ��¼��;




1.��ѯ��1ҳԱ������, ÿҳչʾ10����¼
select* from emp limit 0, 10;
select* from emp limit 10;



2.��ѯ��2ҳԱ������, ÿҳչʾ10����¼   -------- > (ҳ�� - 1)* ҳչʾ��¼��
select* from emp limit 10, 10;




3.��ѯ�Ա�Ϊ��, ��������20 - 40��(��)���ڵ�ǰ5��Ա����Ϣ, �Բ�ѯ�Ľ����������������, ������ͬ����ְʱ����������
select* from emp where gender = '��' and age between 20 and 40 order by age asc, entrydate asc limit 5;


















