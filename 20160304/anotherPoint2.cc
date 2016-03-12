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
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
public:
	//explicit 
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int )" << endl;
	}
	//1.类型转换函数必须是成员函数
	//2.类型转换函数没有返回值类型，但是在
	//函数体内必须以传值方式返回一个目标类型变量
	//3.类型转换函数没有函数参数
	//4.不要轻易使用
	operator int ()//转换为int型
	{
		return _ix;
	}

	operator double()//转换为doulbe型的
	{
		return _ix *_iy;
	}

	operator AnotherPoint()//转换成AnotherPoint
	{
		return AnotherPoint(_ix, _iy);//通过返回创建AnotherPoint
	}
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
	Point pt1(4,5);//创建Point对象
	cout << pt1 << endl;

	int x1 = pt1;//将Point类型转换为int型
	cout << x1 << endl;
	
	double d = pt1;
	cout << d << endl;

	AnotherPoint ap = pt1;//将其转为AnotherPoint类型
	cout << ap << endl;
}
