
����ֶ�
ALTER TABLE����ADD�ֶ�������(����)��COMMENTע��][Լ��]:




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

Ϊemp������һ���µ��ֶΡ��ǳơ�Ϊnickname, ����Ϊvarchar(2O)

alter table emp add nickname varchar(20)comment'�ǳ�';




�޸���������
ALTER TABLE����MODIFY�ֶ�������������(����);

�޸��ֶ������ֶ�����
ALTER TABLE����CHANGE ���ֶ��� ���ֶ��� ����(����)[COMMENTע��][Լ��];



��emp���nickname:�ֶ��޸�Ϊusername, ����Ϊvarchar(30)

alter table emp change nickname username varchar(30)comment'�û���';



ɾ���ֶ�
ALTER TABLE ���� DROP�ֶ���;



��emp����ֶ�usernameɾ��
alter table emp drop username;



�޸ı���
ALTER TABLE ���� RENAME TO �±���;





ɾ����
DROP TABLE[IF EXISTS]����;
ɾ��ָ����, �����´����ñ�
TRUNCATE TABLE ����;






�������(INSERT)
�޸�����(UPDATE)
ɾ������(DELETE)

��ָ���ֶ��������
INSERT INTO����(�ֶ���1, �ֶ���2, )VALUES(ֵ1, ֵ2...);
��ȫ���ֶ��������
INSERT INTO����VALUES(ֵ1, ֵ2, );


�޸�����
UPDATE ���� SET �ֶ���1 = ֵ1, �ֶ���2 = ֵ2, [HERE����];


ɾ������
DELETE FROM����[WHERE����]

DELETE��䲻��ɾ��ĳһ���ֶε�ֵ(����ʹ��UPDATE)��




















































