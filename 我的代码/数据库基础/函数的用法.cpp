CONCAT(S1, S2, ...Sn)
�ַ���ƴ��, ��S1, S2, Snƴ�ӳ�һ���ַ���            select concat('Hello', MySQL');
LOWER(str)
���ַ���strȫ��תΪСд                            select Lower('Hello');
UPPER(str)
���ַ���strȫ��תΪ��д
LPAD(str, n, pad)                                
�����, ���ַ���pad��str����߽������, �ﵽn���ַ�������       select lpad('01', 5, -')
RPAD(str, n, pad)
�����, ���ַ���pad��str���ұ߽������, �ﵽn���ַ������� 
TRIM(str)
ȥ���ַ���ͷ����β���Ŀո�                            select trim('Hello MySQL )
SUBSTRING(str, start, len) 
���ش��ַ���str��startλ�����len�����ȵ��ַ���      select substring('Hello MySQL', 1, 5); û�е����λ��



1.����ҵ��������, ��ҵԱ���Ĺ���, ͳһ5λ��, Ŀǰ����5λ����ȫ����ǰ�油0������:1��Ա���Ĺ���Ӧ��Ϊ00001��
update emp set workno = lpad(workno, 5, '0');






CEIL(x)
����ȡ��  select ceil(1.1);
FLOOR(x)
����ȡ��   select floor(1.9);
MOD(x, y)
����x / y��ģ   select mod(3, 4);
RAND()
����0~1�ڵ������   select rand();
ROUND(x, y)
�����x�����������ֵ, ����yλС��   select round(2.345, 2);



����:ͨ�����ݿ�ĺ���, ����һ����λ���������֤�롣
select round(rand() * 1000000, 0);
select lpad(round(rand() * 1000000, 0), 6, '0');   ��Ҫ���㣬��Ȼ�п��ܲ�����λ





CURDATE()
���ص�ǰ����   select curdate();
CURTIME()
���ص�ǰʱ��    select curtime();
NOW()
���ص�ǰ���ں�ʱ��
YEAR(date)
��ȡָ��date�����
MONTH(date)
��ȡָ��date���·�
DAY(date)
��ȡָ��date������ 

select YEAR(now());
select MONTH(now());
select DAY(now());




DATE ADD(date, INTERVAL expr type)
����һ������ / ʱ��ֵ����һ��ʱ����eXpr���ʱ��ֵ

select date_add(now(), INTERVAL 76 DAY); ��ǰʱ������70��


DATEDIFF(date1, date2)
������ʼʱ��date1�ͽ���ʱ��date2֮�������

se1ect datediff('2021-12-01', '2021-11-01');






����:��ѯ����Ա������ְ����, ��������ְ������������
select name, datediff(curdate(), entrydate)from emp;


select name, datediff(curdate(), entrydate)as 'entrydays'from emp order by entrydays desc;






IF(value, t, f)
���value:Ϊtrue, �򷵻�t, ���򷵻�f    select if (false, 'Ok', 'Error');
IFNULL(valye1, value2)
���value1��Ϊ��, ����value1, ���򷵻�value2   select ifnull(null, 'Default');
CASE WHEN[val1] THEN[res1]...ELSE[default] END
���vallΪtrue, ����res1, .���򷵻�defaultĬ��ֵ
CASE[expr] WHEN[val1] THEN[res1]...ELSE[default] END
���expr��ֵ����vall, ����res1, .���򷵻�defaultĬ��ֵ



����:��ѯmp���Ա�������͹�����ַ
(���� / �Ϻ�---- > һ�߳���, ����---- > ���߳���)
select name, (case workaddress when'����'then'һ�߳���'when'�Ϻ�'then'���߳���'eLse'���߳���'end)as'������ַ' from emp;







select
id,
name,
(case when math >= 85then'����'when math >= 60then'����'else'������'end)'��ѧ',
(case when english >= 85then'����'when english >= 60then'����'eLse'������'end)'Ӣ��',
(case when chinese >= 85then'����'when chinese >= 60then'����'else'������'end)'����' from score;





























