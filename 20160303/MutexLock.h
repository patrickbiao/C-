 ///
 /// @file    MutexLock.h
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-04 20:17:34
 ///
 
//每次写之前先定义一个条件宏,这样保证重复调用时
//只被定义一次,如果检测到有这个宏，宏之间的
//代码就不会被执行
#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__

#include <iostream>

class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();//通过类的方式写代码
	void unlock();//以后使用就直接通过类调用
	pthread_mutex_t * getMutexPtr();//返回指针
//	{
//		return &_mutex;
//	}
private:
	pthread_mutex_t _mutex;
//	static pthread_mutex_t _mutex;
//	不能定义成静态的，由于使用互斥锁时，是可以
//	创建多把锁的，如果定义成静态，则这个锁可以
//	被这个类共享,即通过这个类只能创建一把锁
};
#endif
