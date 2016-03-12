 ///
 /// @file    operatorArrow.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-10 23:34:02
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Data
{
public:
	int getlen()
	{
		return 5;
	}
};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{
		cout << "DataPtr()" << endl;
	}

	~DataPtr()
	{
		cout << "~DataPtr()" << endl;
		delete _pData;
	}
	Data * operator->() 
	//重载箭头运算符，返回的值是指向的Data的指针
	{
		cout << "operator->()" << endl;
		return _pData;
	}
private:
	Data * _pData;
};

int main(void)
{
	DataPtr dp;
	cout << dp->getlen() << endl;
	//dp重载了箭头运算符，从而返回Data指针，
	//进而通过这个指针去调用get函数,相当于：
	cout << (dp.operator->())->getlen() << endl;
}
