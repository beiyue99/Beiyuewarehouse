



--ת�˲���(����������ת��1000)
--1.��ѯ�����˻����
select * from account where name = '����';
--2.�������˻���� - 1000
update account set money = money - 1000 where name = '����';
--3.�������˻���� + 1000
update account set money = money + l000 where name = '����';





�鿴 / ���������ύ��ʽ
SELECT @@autocommit
SET @@autocommit = 0;   //����Ϊ�ֶ��ύ    ֮��ִ��ָ�����Ҫ����commit������������Իع�
�ύ����
COMMIT
�ع�����
ROLLBACK;




//����Ҫ�����ύ��ʽ
��������
START TRANSACTION BEGIN
�ύ����
COMMIT;                ִ�к�������ύ����ô������ݾͲ���仯
�ع�����
ROLLBACK;



���
һ�������������һ������û���ύ�����ݡ�
�����ظ���
һ�������Ⱥ��ȡͬһ����¼, �����ζ�ȡ�����ݲ�ͬ, ��֮Ϊ�����ظ�����   //����һ���ն�commitһ��ָ��󣬵�ǰ�ն��ٴβ飬�ͻ���ֲ�ͬ
�ö�
һ��������������ѯ����ʱ, û�ж�Ӧ��������, �����ڲ�������ʱ, �ַ������������Ѿ�����, ��������ˡ���Ӱ����



�鿴������뼶��
SELECT @@TRANSACTION_ISOLATION;
-����������뼶��
SET[SESSION | GLOBAL] TRANSACTION ISOLATION LEVEL{ READ UNCOMMITTED | READ COMMITTED | REPEATABLE READ | SERIALIZABLE }
//���һ��ֻ�������һ��������ˣ�������ֻö���
















































