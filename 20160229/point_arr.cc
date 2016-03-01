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
#if 1
	Point()
	{
		cout << "Point()" << endl;
	}
#endif
	Point(int ix,int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int )" << endl;
		static int iCount = 0;//记录被调用几次
	    ++iCount;//++i比i++效率更高
		cout << "调用 " << iCount << "次构造函数" << endl;
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
	//Point ptArr1[2];//调用默认构造函数初始化数组
	//
	Point ptArr2[2] = {Point(1,2),Point(3,4)};
	//大括号中创建的对象是没有名字的，称匿名对象（类名（））
	//但是可以通过数组来访问匿名对象
	Point ptArr3[] = {Point(5,6),Point(7,8)};
	Point ptArr4[5] = {Point(1,2),Point(8,9)};
}
