//
 /// @file    Condition.h
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-04 20:53:17
 ///
 
#ifndef __CONDITION_H__
#define __CONDITION_H__

#include <pthread.h>
//前身声明
class MutexLock;//前身声明MutexLock是一个类，由于没涉及到具体操作
				//没必要将定义引进来，如果没这样做，得加上MutexLock的
				//头文件

class Condition
{
public:
	Condition(MutexLock & _mutex);
	~Condition();

	void wait();//等待,使用条件变量需要与锁结合
	void notify();//通知(单播)
	void notifyAll();//广播
private:
	pthread_cond_t _cond;//每次使用条件变量,都要跟互斥锁发生关系,所以
	MutexLock & _mutex;//在Condition函数构造时，就要与互斥锁联系起来
	//该引用表示对象已经是创建好的
};
#endif
