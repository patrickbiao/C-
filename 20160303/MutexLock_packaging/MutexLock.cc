 ///
 /// @file    MutexLock.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-04 20:16:35
 ///
 
#include "MutexLock.h"//实现文件中源码的第一条
					  //必须是对应的头文件
#include <pthread.h>//不然可能会出现编译出错
//#include <iostream>

//通过创建对象直接调用以下类成员函数
MutexLock::MutexLock()//类外实现构造函数，而非调用
{
	pthread_mutex_init(&_mutex,NULL);//初始化类中的锁
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
//完成lock的实现
pthread_mutex_t * MutexLock::getMutexPtr()
{
	return &_mutex;
}



