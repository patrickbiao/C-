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
	Point() 
	: _ix(0)
	, _iy(0)//真正的初始化过程
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
	Point point;//调用默认构造函数Point()，进行初始化
	point.printf();
	return 0;
}
