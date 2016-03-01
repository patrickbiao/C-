 ///
 /// @file    const_object.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-01 11:49:59
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix=0,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int )" << endl;
	}

	~Point()
	{//因为没涉及堆空间操作，可有可无
		cout << "~Point()" << endl;
	}

	void setX(int ix)
	{
		_ix = ix;
	}

	void setY(int iy)
	{
		_iy = iy;
	}

	void printf() 
	{
		cout << "(" << _ix 
			 << "," << _iy 
			 << ")" << endl;
	}
	void printf() const
	{
		cout << "const ->(" << _ix 
			 << "," << _iy 
			 << ")" << endl;
	}
private:
	  int _ix;
	  int _iy;
};

int main(void)
{
	Point pt(3,4);
	pt.printf();//非const的对象可以调用非const和const成员函数
	pt.setX(5);//Pt不是const对象，是可以被修改的
	pt.setY(6);

	pt.printf();
	const Point pt2(1,2);
	pt2.printf();//const对象（常对象）无法调用非const成员函数
				 //只能调用const成员函数
	//const的成员对象，只能进行读取
}
