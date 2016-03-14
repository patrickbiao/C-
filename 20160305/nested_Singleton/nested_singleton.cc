 //
 /// @file    Singleton.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-13 20:36:52
 ///
 
#include <iostream>
#include <stdio.h>

using std::cout; 
using std::endl;

class Singleton
{
public:
//	static void destroy();
	static Singleton * getInstance();
private:
	class AutoRelease//定义一个内部类
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}
		~AutoRelease()
		{
			if(_pInstance != NULL)//由于是内部类，可以直接使用该指针
				delete _pInstance;
			cout << "~AutoRelease()" << endl;
		}
	};
	Singleton();
	~Singleton();
private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
    //将对象声明为静态的，才能在结束时调用析构函数
};

Singleton * Singleton::_pInstance = NULL;//静态数据成员进行初始化
Singleton::AutoRelease Singleton::_autoRelease;//创建对象

Singleton * Singleton::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Singleton;
	}
	return _pInstance;
}

Singleton::Singleton()
{
	cout << "Singlegton()" << endl;
}

Singleton::~Singleton()
{
	cout << "~Singleton()" << endl;
}

#if 0
void Singleton::destroy()
{
	delete _pInstance;
}
#endif

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	//Singleton::destroy();
	return 0;
}
