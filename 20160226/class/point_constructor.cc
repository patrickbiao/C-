 //
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
	: _ix(0)
	, _iy(0)//真正的初始化过程
	{
		cout << "Point()" << endl;
		//_ix = 10;
		//_iy = 20;//这里表示的是赋值语句
	}

	//添加一个有参构造函数
   //explicit Point(int ix,int iy=0)
   //explicit意思是该构造函数要显式调用，下面的3转成point对象
   //属于稳式调用构造函数，所以找不到这个函数
	explicit Point(int ix,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int)" << endl;
	}
	//如果不显式定义析构函数，系统会自动为我们提供一个析构函数
	~Point() //当对象pt被销毁时，会自动调用析构函数
	{
		cout << "~Point()" << endl;
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
	Point pt1;//调用默认构造函数Point(),pt1为栈对象
	pt1.printf();
	cout << endl;
//	由于上面声明为显式调用，所以这里出错
//	Point pt2 = 3;//等价于Point pt2(3);
	//稳式转换，即当用3去初始化pt2时，会通
	//过3去找传递一个参数的构造函数,通过相应的构造函数创建
	//一个临时对象，再将这个临时对象通过复制构造函数来初始化pt2
//	pt2.printf();
	return 0;
}
