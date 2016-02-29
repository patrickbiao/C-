 ///
 /// @file    computer.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-29 19:40:23
 ///
 
#include <iostream>
#include <string.h>

using std::endl;
using std::cout;

class Computer
{
public:
	Computer(const char * brand,float fprice);
	~Computer();
	//因为静态成员函数没有this指针，所以要提供一个
	//对象的引用，让其知道要打印哪一个对象
	static void printf(Computer & com);
	static void printf_total();
private:
	char * _brand;
	float _fprice;//类的大小为该变量的大小
	static float _ftotalPrice;//该变量没有存放在栈区，
	              //一个公共的数据,都可以来访问	
	//static Point _pt1;
};

float Computer::_ftotalPrice = 0.0f;//普通变量
//

Computer::Computer(const char * brand,float fprice)
: _fprice(fprice)
{
	cout << "Computer(float fprice)" << endl;
	_brand = new char[strlen(brand)+1];
	strcpy(_brand,brand);
	_ftotalPrice += _fprice;
}

Computer::~Computer()
{
	if(_brand)
		delete [] _brand;
	_ftotalPrice -= _fprice;
	cout << "~Computer()" << endl;
}

void Computer::printf(Computer & com)
{
	cout << "价格：" << com._fprice << endl;
	cout << "总价：" << com._ftotalPrice << endl;
}

void Computer::printf_total()
{
	cout << "总价：" <<_ftotalPrice << endl;
}
int main(void)
{
	Computer pc1("IBM",7000);
	//静态成员函数是可以通过类名来调的
	//静态成员函数没有this指针，如果想要访问对象的数据时
	//必须要传一个参数过来
	Computer::printf(pc1);//通过类名调用
	Computer::printf_total();
	cout << endl;
	Computer pc2("Dell",8000);
	pc2.printf(pc2);//通过对象调用，把自己传进去
	pc2.printf_total();

	pc2.~Computer();
	pc2.printf_total();
}
