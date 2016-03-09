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
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex()" << endl;		
	}

	Complex operator + (const Complex & rhs)//返回对象
	//重载加法运算符函数,由于第一个参数为对象本身this
	//所以只需要传第二个参数
    //Complex operator + (const Complex & lhs,const Complex & rhs)
	{
		//直接使用Complex的构造函数
		return Complex(this->_dreal + rhs._dreal,
					   this->_dimag + rhs._dimag);
	}
#if 0
	//返回对象与返回引用的差别		
	Complex & operator + (const Complex & rhs)
	//返回引用，则this指针会发生变化,即返回引用
	//都是为了改变对象本身，所以用上一种方式，因为
	//我们执行a+b=c时，不希望执行完改变a b值
	{
		//直接使用Complex的构造函数
		this->_dreal += rhs._dreal;
		this->_dimag += rhs._dimag;
		return * this;
	}
#endif
	Complex & operator += (const Complex & rhs)
	{
		this->_dreal += rhs._dreal;
		this->_dimag += rhs._dimag;
		return * this;
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
//private:
public://由于下面要使用到他，所以用public
	double _dreal;
	double _dimag;
};


//以全局函数or自由函数进行重载
int main(void)
{
	int a = 3;
	int b = 4;
	int c = a + b;

	a = a + b;
	a += b;

	Complex c1(1.0, 2.0);
	Complex c2(3.0, -4.0);
	Complex ret  = c1 + c2;
	//希望加法操作也能适用于自定义类型
	ret.display();
	cout << "c1 = ";
	c1.display();
	cout << endl; 
	c1 += c2;
	cout << "c1 = ";
	c1.display();
}
