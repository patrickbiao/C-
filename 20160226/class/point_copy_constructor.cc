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
	~Point() //当对象被销毁时，系统会自动调用析构函数
	{
		cout << "~Point()" << endl;
	}

	//如果我们不显式定义析构函数，系统会自动为我们提供一个析构函数
	//why复制构造函数的参数必须是引用：否则无限递归
	//引用符号&不能去掉，因为只传对象的引用，如果去掉&，则类似于：
	//const Point rhs = pt1（形参与实参的结合）,这样与main中的Point pt2 = pt1没有差别
	//这样又会重新回到形参与实参的结合，无限递归压栈造成栈溢出（每个函数都有自己的栈空间）
	Point(const Point & rhs)//复制构造函数本质也是构造函数，所以也有初始化
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point & rhs)" << endl;
	}
	void printf()
	{
		cout << "(" << _ix << ", " << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

Point func()
{
	Point pt;
	return pt;//执行return时，会对pt进行复制：
}
int main(void)
{
	Point pt1;//调用默认构造函数Point()，进行初始化,pt1为栈对象
	pt1.printf();
	cout << endl;//换行

	Point pt2 = pt1;//系统会调用复制构造函数
	pt2.printf();
	return 0;
}

