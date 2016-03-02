 ///
 /// @file    singleton.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-01 22:45:38
 ///
 
//单例模式的对象：
//1.不能是栈对象
//2.应该是一个堆对象
//3.不能直接通过new的方式去创建堆对象
//4.需要把构造函数放入private区域
//5.用静态成员函数来创建对象
//6.创建好的对象需要使用静态数据成员进行保存
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()//static成员函数，返回值是Single指针
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			//申请了一个指向该对象的指针，执行该语句，相当于创建一个对象
			//会调用构造函数，如果没有执行，则不会调用构造函数
		}
		return  _pInstance;//返回Single类型的指针
	}

	static void destroy()
	{
		delete _pInstance;//删除时，调用析构函数
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()
	{
		cout << "~Singleton()"  << endl;
	}
private:
	static Singleton * _pInstance;//静态成员函数需在类之外定义
};

Singleton * Singleton::_pInstance = NULL;

int main(void)
{
//	Singleton * p1 = new Singleton;
//希望该语句不能正常执行，所以将Singleton放在private中，这样不能在类外直接使用
//由于执行这语句时需要调用构造函数（当创建对象时，构造函数被自动调用）
//	Singleton * p2 = new Singleton;
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	//p2->destroy();
	Singleton::destroy();//静态成员函数，可以直接通过类名调用
	return 0;
}
