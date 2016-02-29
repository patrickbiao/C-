 ///
 /// @file    point.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-28 22:08:53
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy);//有参构造函数

	Point(const Point & rhs);//复制构造函数

	void printf();

private:
	const int _ix;//常量的初始化必须放在初始化列表里面进行
	const int _iy;
};

Point::Point(int ix,int iy)//构造函数
: _ix(ix)
, _iy(iy)
{
//	_ix = ix;//赋值语句，并不是初始化的过程,所以会报错
//	_iy = iy;//对于常量放在初始化链表中初始化
	cout << "Point(int ix,int iy)" << endl;
}

Point::Point(const Point & rhs)//复制构造函数
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point & rhs)" << endl;					
}

void Point:: printf()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	Point pt1(1,2);
	pt1.printf();
}
