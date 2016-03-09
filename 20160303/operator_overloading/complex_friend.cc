 ///
 /// @file    complex.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-07 23:32:29
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Complex
{
	friend Complex operator + (const Complex & lhs,const Complex & rhs);
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex()" << endl;		
	}
	void display()
	{
		cout << _dreal;
		if(_dimag > 0)
			cout << " + " << _dimag << "i" << endl;
		else if(_dimag ==0)
			cout << endl;
		else 
			cout << " - " << -1 * _dimag << 'i' << endl;

	}
private:
	double _dreal;
	double _dimag;
};

//普通函数不能去访问类中的私有成员，声明为友元之后可以
Complex operator + (const Complex & lhs,const Complex & rhs)
{
	//直接使用Complex的构造函数
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}
int main(void)
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, -4.0);
	Complex ret  = c1 + c2;
	//希望加法操作也能适用于自定义类型
	ret.display();
}
