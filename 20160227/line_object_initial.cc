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
#if 0
	Point()//无参(默认)构造函数
	: _ix(0)
	, _iy(0)
	{
		
	}
#endif
	Point(int ix,int iy);//有参构造函数

	Point(const Point & rhs);//复制构造函数

	void printf();

private:
	 int _ix;
	 int _iy;
};

Point::Point(int ix,int iy)//形参为参数称有参构造函数
: _ix(ix)
, _iy(iy)
{
	cout << "Point(int ix,int iy)" << endl;
}

Point::Point(const Point & rhs)//形参为对象本身称复制构造函数
: _ix(rhs._ix)
, _iy(rhs._iy)
{
	cout << "Point(const Point & rhs)" << endl;
}

void Point::printf()
{
	cout << "(" << _ix 
		 << "," << _iy
		 << ")" << endl;
}

class Line
{
public:
	Line(int x1,int y1,int x2,int y2);//有参构造函数
	Line(const Line & rhs);//复制构造函数
	void draw();
private:
	Point _pt1;
	Point _pt2;
};

//如果不显式初始化Point对象 _pt1,_pt2,，系统自动去调用
//Point的默认构造函数去创建 _pt1,_pt2,如果只给Point提供有参
//构造函数就会报错
Line::Line(int x1,int y1,int x2,int y2)
: _pt1(x1,y1)//传的是参数，
, _pt2(x2,y2)//显式调用对象的有参构造函数
{
	cout << "Line(int x1,int y1,int x2,int y2)"	<< endl;
}
Line::Line(const Line & rhs)//传的是一个对象,调用复制构造函数
: _pt1(rhs._pt1)//传的是一个对象，调用复制构造函数
, _pt2(rhs._pt2)//显式调用对象的复制构造函数
{
	cout << "Line(const Line & rhs)" << endl;	
}
void Line::draw()
{
	 _pt1.printf();
	 cout << " to " ;
	 _pt2.printf();
}
int main(void)
{
	Line line(1,2,3,4);//调用有参构造函数
	line.draw();

	Line line2(line);//调用复制构造函数 
	line2.draw();
	
	return 0;
}
