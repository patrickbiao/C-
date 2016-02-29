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
	Point(int ix,int iy,double & z);//有参构造函数

	Point(const Point & rhs);//复制构造函数

	void printf();
	
	void setX(int ix);

private:
	int _ix;
	int _iy;
	int & _ref1;//引用必须要在初始化列表中进行初始化
	double & _ref2;
};

Point::Point(int ix,int iy,double &z)//构造函数
: _ix(ix)
, _iy(iy)
, _ref1(_ix)//由于为引用，因此需要与全局变量绑定,因为引用一经绑定，不能修改.
, _ref2(z)//当用局部变量ix or iy绑定时，由于局部变量只在调用所在函数时才有效，
	      //当调用复制构造函数时，由于没有调用构造函数，故ref1中得不到正确结果
{
//	_ix = ix;//赋值语句，并不是初始化的过程,所以会报错
//	_iy = iy;//对于常量放在初始化列表中初始化
	cout << "Point(int ix,int iy)" << endl;
}

Point::Point(const Point & rhs)//复制构造函数
: _ix(rhs._ix)
, _iy(rhs._iy)
, _ref1(rhs._ref1)
, _ref2(rhs._ref2)
{
	cout << "Point(const Point & rhs)" << endl;					
}

void Point:: printf()
{
	cout << "(" << _ix
		 << "," << _iy
		 << "," << _ref1
		 << "," << _ref2
		 << ")" << endl;
}

void Point::setX(int ix)
{
	_ix = ix;
}

int main(void)
{
	double d1 = 5.0;
	Point pt1(1,4,d1);
	pt1.printf();
	Point pt2 = pt1;//point pt2(pt1);
	pt2.printf();
	cout << "修改pt1之中的_ix的值之后" << endl;
	pt1.setX(7);//引用一经绑定，永远指向他，他变，另一个也变
	pt1.printf();
	pt2.printf();
}
