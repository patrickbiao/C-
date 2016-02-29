 ///
 /// @file    computer.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-29 19:40:23
 ///
 
#include <iostream>

using std::endl;
using std::cout;

class Computer
{
public:
	Computer(float fprice);
	
	~Computer();
	void printf();

private:
	float _fprice;//类的大小为该变量的大小
	static float _ftotalPrice;//该变量没有存放在栈区，
	              //一个公共的数据,都可以来访问	
	//static Point _pt1;
};

float Computer::_ftotalPrice = 0.0f;//普通变量
//

Computer::Computer(float fprice)
: _fprice(fprice)
{
	cout << "Computer(float fprice)" << endl;
	_ftotalPrice += _fprice;
}

Computer::~Computer()
{
	_ftotalPrice -= _fprice;
}

void Computer::printf(/*Computer * const this*/)
{// this代表对象本身，它是一个称其的参数
	cout << "价格：" << this->_fprice << endl;
	cout << "总价：" << _ftotalPrice << endl;
}

int main(void)
{
	Computer pc1(7000);
	cout << "After buy pc1" << endl;
	pc1.printf();

	Computer pc2(5000);
	cout << "After buy pc2" << endl;
	pc2.printf();

	cout << "pc1的存储空间:" << sizeof(pc1) << endl;
	cout << "Computer的存储空间：" << sizeof(Computer) << endl;
}
