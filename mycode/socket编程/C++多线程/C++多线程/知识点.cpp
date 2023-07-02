#define _CRT_SECURE_NO_WARNINGS 1


//  joinable 判断是否还能detach或join    返回真和假
//thread myobj([]() {cout << "wwwww" << endl; });


//unique_lock的release函数使得与之绑定的互斥量分离，如果此时该互斥量处于锁定状态，需要后续手动unlock

//new在堆区的内存，如果不手动调用delete，则不会执行析构函数！



			//defer_lock：前提为没锁。 作用是初始化一个没加锁的互斥量
			//比如 unique_lock<mutex> sbguard1(my_mutex1,defer_lock)
			// 再调用  sbguard1.lock()   该类封装的lock函数会自己解锁，所以后续不需要手动unlock
			//该类也封装有unlock函数，以便更灵活的操作数据



			//try_lock函数用法与try_to_lock类似
			//if(sbguard1.try_lock==true)  表示拿到锁了，接下来可以操作数据