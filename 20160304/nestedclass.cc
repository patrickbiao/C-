 ///
 /// @file    nestedclass.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-11 23:59:08
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Line
{
public:
	class Point
	{
	public:
		Point(int ix = 0,int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int, int)" << endl;
		}

		void printfPoint();
	private:
		int _ix;
		int _iy;
	};

public:
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)//对创建的对象进行初始化
	, _pt2(x2, y2)
	{
		cout << "Line(int, int, int, int)" << endl;
	}

	void printfLine()
	{
		_pt1.printfPoint();	
		cout << "--->";
		_pt2.printfPoint();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};

void Line::Point::printfPoint()//作用域有几层就写几层
{
	cout << "(" << _ix << "," << _iy << ")";
}

int main(void)
{
	Line line(1,2,3,4);//通过Line创建两个点
	line.printfLine();

	Line::Point pt(10,12);//通过Line直接创建Point内部类
	pt.printfPoint();
	cout << endl;
}
