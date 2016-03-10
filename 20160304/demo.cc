 ///
 /// @file    demo.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-10 21:13:51
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Demo
{
public:
	double operator()(double x, double y)
	{
		return x > y ? x:y;
	}
	
	double operator()(double x, double y, double z)
	{
		return (x+y)*z;
	}
};	

int main (void)
{
	Demo demo;//重载了函数调用运算符的对象称为函数对象
			  //函数对象可以作为函数使用
	cout << demo(3,4) << endl;
	cout << demo(3,4,5) << endl;
	return 0;
}
