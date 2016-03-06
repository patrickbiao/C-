 ///
 /// @file    Condition.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-04 21:26:17
 ///
 
#include "Condition.h" 
//由于该实现文件是真正要使用MutexLock函数，即跟实现有关系了，故加上头文件
#include "MutexLock.h"

Condition::Condition(MutexLock & lock)//类外实现函数
: _mutex(lock)//由于是引用，必须在初始化列表中进行初始化
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond, _mutex.getMutexPtr());
	//由于定义中使用的是引用，所以用 .
	//这里要获得MutexLock原生的指针,通过引用解决了这个问题
	//所以在MutexLock对象中加上一个获取指针的函数
} 

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}
