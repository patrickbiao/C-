 ///
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
	static void destroy();
	static Singleton * getInstance();
private:
	Singleton();
	~Singleton();
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;//静态数据成员进行初始化

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

void Singleton::destroy()
{
	delete _pInstance;
}

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	Singleton::destroy();
}
