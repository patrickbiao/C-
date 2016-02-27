 ///
 /// @file    computer.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 17:06:10
 ///
 
#include <iostream>
#include <stdio.h>
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
	}
	void setBrand(char * brand);
	void setPrice (float fprice);
	void printf();
private:
	char * _brand;//类的成员变量用m_ or _
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

int test(void)
{
	int a;//也可以将a看成一个int型的对象
	Computer pcl;//创建一个类的实例化：Computer为类型,pcl为实例,只有实例化之后系统才为对象分配存储空间
	//pcl._fprice = 10;//信息隐藏，不能在类外使用私有成员
	pcl.setPrice(5000);
	pcl.setBrand("Dell");
	pcl.printf();
	//pcl.printf();//将其移到私有函数中，类外不能使用它
	return 0;
}

int test1(void)
{
	Computer pcl;//会调用默认构造函数 default construction
	pcl.printf();
	cout << endl;
	Computer pc2("Lenvon",6000);//会调用有参构造函数
	pc2.printf();
	return 0;
}

int main(void)
{	
	Computer *pCom = new Computer;//用new运算符创建对象，进而调用构造函数
	pCom->printf();
//	pCom->~Computer();//析构函数是可以显式调用的，但是一般不这样用

	delete pCom;
}
