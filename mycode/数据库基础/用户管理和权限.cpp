1.��ѯ�û�
USE mysql;
SELECT* FROM user;
2.
�����û�
CREATE USER '�û���'@'������'IDENTIFIED BY'����';


�����û�
itcast, �ܹ��ڵ�ǰ����Loca1h0st����, ����123456;
create user 'itcast'@'localhost'identified by '123456';        

--�����û�heima,
�����������������ʸ����ݿ�, ����123456:
create user 'heima'@'%'identified by '123456';




3.
�޸��û�����
ALTER USER'�û���'@'������'IDENTIFIED WITH mysql_native_ password BY'������';

�޸��û�heima�ķ�������Ϊ1234 :
alter user 'heima'@'%'identified with mysql_native_password by 1234;




4.ɾ���û�
DROP USER'�û���'@'������';

drop user 'heima'@'%';    ɾ��heima�û�




SELECT CURRENT_USER();   �鿴��ǰ�û�
SELECT User, Host FROM mysql.user;  �鿴�����û�
SELECT User, Host FROM mysql.user WHERE User = 'your_username';  �鿴�ض��û�








DCL - Ȩ�޿���
1.��ѯȨ��
SHOW GRANTS FOR '�û���'@'������';








2.����Ȩ��
GRANTȨ���б�ON ���ݿ���.���� TO���û���'@'������';


grant all on itcast.* to 'heima'@'%';

//����Ȩ֮ǰ��show databases;  ������itcast���ݿ⣬��Ȩ����Կ���
3.����Ȩ��
REVOKEȨ���б�ON���ݿ���.���� FROM���û���'@'������';

--����Ȩ��
revoke all on itcast.*from 'heima'@'%';








































