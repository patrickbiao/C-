 ///
 /// @file    friend.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-06 23:28:55
 ///
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point & lhs,const Point & rhs);
	//声明友元函数，传入左右操作数
public:
	Point(int ix =0,int iy=0)
	: _ix(ix)//构造函数的初始化放到初始化列表中
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}
	
	void printf()
	{
		cout << "(" << _ix << "，" << _iy << ")" <<  endl;
	}
private:
	int _ix;
	int _iy;
};
 
float distance(const Point & lhs,const Point & rhs)//友元函数的实现
{
	return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix)+
			    (lhs._iy -rhs._iy)*(lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1,2);
	pt1.printf();
	Point pt2(4,5);
	pt2.printf();
	cout << endl;

	cout << "pt1 与 pt2 的距离：";
	cout << distance(pt1,pt2) << endl;
}
