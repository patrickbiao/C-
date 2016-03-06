 ///
 /// @file    test.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-04 22:48:36
 ///
 
#include "MutexLock.h"
#include "Condition.h"
#include <unistd.h>
#include <pthread.h>//创建线程需要
#include <iostream>
using std::cout;
using std::endl;

int iCount = 100;//互斥访问一个全局变量
MutexLock mutexlock;//定义全局锁，两线程都可以使用
Condition condition(mutexlock);

void * thread1(void * arg)//线程执行体
{
	while(1)
	{
		mutexlock.lock();//先锁上，再访问
		//if(iCount < 90)//如果大于90执行wait
		while(iCount < 90)//切记：不要使用if进行判断
			condition.wait();
		--iCount;
		cout << "iCount = " << iCount << endl;
		mutexlock.unlock();
		condition.notify();//相互发通知
		sleep(1);
	}
}

void * thread2(void * arg)
{
	while(1){
	mutexlock.lock();
	while(iCount > 90)
		condition.wait();
	
	++iCount;
	cout << "iCount = " << iCount << endl;
	mutexlock.unlock();
	condition.notify();
	sleep(2);}
}
int main(void)
{
	pthread_t pth1;
	pthread_t pth2;

	pthread_create(&pth1,NULL,thread1,NULL);
	pthread_create(&pth2,NULL,thread2,NULL);

	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);

}
