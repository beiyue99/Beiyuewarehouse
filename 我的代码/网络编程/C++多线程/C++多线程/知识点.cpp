#define _CRT_SECURE_NO_WARNINGS 1


//  joinable �ж��Ƿ���detach��join    ������ͼ�
//thread myobj([]() {cout << "wwwww" << endl; });


//unique_lock��release����ʹ����֮�󶨵Ļ��������룬�����ʱ�û�������������״̬����Ҫ�����ֶ�unlock

//new�ڶ������ڴ棬������ֶ�����delete���򲻻�ִ������������



			//defer_lock��ǰ��Ϊû���� �����ǳ�ʼ��һ��û�����Ļ�����
			//���� unique_lock<mutex> sbguard1(my_mutex1,defer_lock)
			// �ٵ���  sbguard1.lock()   �����װ��lock�������Լ����������Ժ�������Ҫ�ֶ�unlock
			//����Ҳ��װ��unlock�������Ա�����Ĳ�������



			//try_lock�����÷���try_to_lock����
			//if(sbguard1.try_lock==true)  ��ʾ�õ����ˣ����������Բ�������