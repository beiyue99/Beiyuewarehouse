

int pthread_join(pthread_t thread, void** retval);
功能:
等待线程结束(此函数会阻塞), 并回收线程资源, 类似进程的wait()函数。如果线程已经结束, 那么该函数会立即返回。
参数 :
thread:被等待的线程号。
retva1 : 用来存储线程退出状态的指针的地址。
返回值 : 成功:0    失败 : 非0







void* fun(void* arg)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("fun thread do working %d\n", i);
		sleep(1);
	}
	return (void*)0x3;
}
int main(void)
{
	int ret = -1;
	void* retp = NULL;
	pthread_t tid = -1;
	//创建一个线程
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (0 != ret)
	{
		printf("pthread_create failed....\n");
		return 1;
	}
	printf("main thread running.....\n");
	//等待线程结束
	ret = pthread_join(tid, &retp);
	if (0 != ret)
	{
		printf("pthread_join failed...\n");
		return 1;
	}
	printf("retp:%p\n", retp);
	printf("main thread exit.....\n");
	return 0;
}


main thread running.....
fun thread do working 0
fun thread do working 1
fun thread do working 2
fun thread do working 3
fun thread do working 4
retp:0x3
main thread exit.....






//输出大写字母
void* fun1(void* arg)
{
	int i = 0;
	for (i = 'A'; i <= 'Z'; i++)
	{
		putchar(i);
		fflush(stdout);
		usleep(100000);//100ms
	}
	return NULL;
}

//输出小写字母
void* fun2(void* arg)
{
	int i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
		fflush(stdout);   //如果不刷新，就会输出在缓冲区
		usleep(100000);//100ms
	}
	return NULL;
}
//模拟输出字符
int main(void)
{
	pthread_t tid1, tid2;
	//创建两个线程
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//等待两个线程结束
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("\n");
	printf("main thread exit....\n");
	return 0;
}

AabBcCDdeEfFgGhHiIjJkKlLmMnNOopPQqrRsStTuUVvwWXxyYZz
main thread exit....








int pthread_detach(pthread_t thread);
功能:
使调用线程与当前进程分离, 分离后不代表此线程不依赖与当前进程, 线程分离的目的是将线程资源的回收工
作交由系统自动来完成, 也就是说当被分离的线程结束之后, 系统会自动回收它的资源。所以, 此函数不会阻塞。
参数 :
thread:线程号。
返回值 :
成功:0
失败 : 非0



调用detach后，线程与主线程分离，主线程不会等待子线程。
如果子线程调用了进程退出函数，整个进程就会结束
而pthread_exit是线程退出函数，等价于return 是退出线程


int main(void)
{
	int ret = -1;
	pthread_t tid = -1;
	//创建一个线程
	ret pthread_create(&tid, NULL, fun, NULL);
	if (0 != ret)
	{
		printf("pthread_create failed....\n");
		return 1;
	}
	printf("main thread....tid:%Lu\n", pthread_self())
		//设置线程分离
		ret pthread_detach(tid);
	if (0 != ret)
	{
		printf("pthread_detach failed...\n");
		return 1;
	}
	printf("按下任意键主线程退出..,,\n");           //如果按下，那么进程退出，所有的线程也终止
	getchar();
	return 0;