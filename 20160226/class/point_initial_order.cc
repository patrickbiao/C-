 ///
 /// @file    point_initial.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 21:07:54
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//初始化列表
	//初始化顺序是由数据成员在声明的顺序决定的
	//这里的结果：(-1076284308, 0)
	Point() 
	: _iy(0)//真正的初始化过程
	, _ix(_iy)
	{
		cout << "Point()" << endl;
		//_ix = 10;
		//_iy = 20;//这里表示的是赋值语句
	}

	void printf()
	{
		cout << "(" << _ix << ", " << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point point;//调用默认构造函数Point()
	point.printf();
	return 0;
}
