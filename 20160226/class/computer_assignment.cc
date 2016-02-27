 ///
 /// @file    computer.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 17:06:10
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer//新定义了Computer这个数据类型
{
public://对外提供接口
	//当只提供有参构造函数时，系统不会再为我们提供默认构造函数
	Computer();//构造函数在类外定义，先声明
	~Computer();//声明析构函数
	Computer(const char * brand,float fprice)
	{//有参构造函数
		int len = strlen(brand);
		_brand = new char[len+1];
		strcpy(_brand, brand);
		_fprice = fprice;
		cout << "Computer(const char * brand,float fprice)" << endl;
	}

	//默认复制构造函数的实现原理:只是简单地将指针的地址复制过来，这样
	//pc1 _brand 和pc2 _brand 都指向同一块堆区，当这两个对象销毁时，
	//都要去调用各自的析构函数，从而产生double free,即默认复制构造函数
	//不能满足需求，所以自己定义

	Computer(const Computer & rhs)//定义复制构造函数，采用引用，rhs即pc1本身
	: _fprice(rhs._fprice)//复制过来
	{
		cout << "Computer(const Computer&)" << endl;
		int len = strlen(rhs._brand);
		_brand = new char[len+1];//而这里，先创建空间，然后把所有数据复制过来，称
		strcpy(_brand,rhs._brand);//深拷贝(double free的问题用深拷贝解决)
	}

	//赋值运算符函数原型：浅拷贝，不会申请堆空间
	//如果不显式定义，系统会自动提供一个赋值运算符函数
	//赋值运算符函数的返回值是引用，如果返回值换成对象，
	//那么会调用复制构造函数，相当于多做了一次冗余的操作，降低效率

	Computer & operator = (const Computer & rhs)
	{
		//_brand = rhs._brand;//浅拷贝，所以会出现double free
		int len = strlen(rhs._brand);
		_brand = new char[len+1];
		strcpy(_brand,rhs._brand);
		_fprice = rhs._fprice;
		cout << "Computer & operater=(const Computer)" << endl;
	
		return *this;//对象本身
	}

	void setBrand(char * brand);
	void setPrice (float fprice);
	void printf();
private:
	char * _brand;//类的成员变量用 m_ or _
	float _fprice;
};

Computer::Computer()//在类之外定义构造函数，第一个为类名，第二个为构造函数
{
	cout << "Computer()" << endl;
	int len = strlen("Dell");
	_brand = new char[len + 1];//申请len+1个字节，最后一个用于放\0
	strcpy(_brand,"Dell");
	_fprice = 4000;
}

Computer::~Computer()
{
	delete [] _brand;//因为申请的是一个数组，所以加【】
	cout << "~Computer()" << endl;
}
//类之外实现成员函数
void Computer::setBrand(char * brand)
{
	strcpy(_brand,brand);		
}

void Computer::setPrice(float fprice)
{
	_fprice = fprice;
}

void Computer::printf()
{
	cout << "品牌：" <<  _brand << endl;
	cout << "价格：" <<  _fprice << endl;
}


int main(void)
{
	int a = 3;
	int b;
	b = a;

	Computer pc1;
	pc1.printf();
	Computer pc2("Mac", 10000);
	pc2 = pc1;//直接调用赋值运算符函数
	pc2.printf();
}
