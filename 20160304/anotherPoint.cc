 ///
 /// @file    anotherPoint.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-10 23:54:26
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class AnotherPoint
{
	friend class Point;
public:	
	AnotherPoint(double dx = 1.0, double dy = 2.0)
	: _dx(dx)
	, _dy(dy)
	{
		cout << "AnotherPoint(double, double)" << endl;
	}
private:
	int _dx;
	int _dy;

	friend std::ostream & operator<<(std::ostream & os,const AnotherPoint & rhs);
};

std::ostream & operator<<(std::ostream & os,const AnotherPoint & rhs)
{
	os << "(" << rhs._dx << "," << rhs._dy << ")" ;
	return os;
}

class Point
{
public:
	//explicit 
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int )" << endl;
	}

//	explicit
	Point(AnotherPoint ap)//在这里访问AP的私有成员，需要将Point设为友元
	: _ix(ap._dx)
	, _iy(ap._dy)
	{
		cout << "Point(AnotherPoint)" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix << "," << rhs._iy << ")" ;
	return os;
}

int main (void)
{
	Point p1;
	cout << "5 转换成 Point";
	//p1 = 5;//隐匿转换
	cout << p1 << endl;

	cout << "double类型转换成";
	double dx = 1.2;
	p1 = dx;
	cout << p1 << endl;

	AnotherPoint ap(12.34, 44.22);
	cout << ap;
	cout << "转换成";
	p1 = ap;//通过构造函数来执行的
	cout << p1;
}
