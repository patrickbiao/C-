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

	Complex & operator += (const Complex & rhs)
	{
		this->_dimag += rhs._dimag;
		this->_dreal += rhs._dreal;
		return * this;
	}

	Complex & operator ++()//前置++
	{//前置++效率更高
		this->_dreal += 1;//因为返回是引用，所以用this
		this->_dimag += 1;
		return *this;
	}

	Complex operator ++(int)
	//int 只是标志，代表这是后置++重载形式
	{
        //由于是返回对象变化之前的值，所以先创建临时对象
		Complex tmp(this->_dreal,this->_dimag);//先保存起来,因为要返回去

		this->_dreal += 1;
		this->_dimag += 1;
		return tmp;//这里会调用复制构造函数
	}
private:
	double _dreal;
	double _dimag;
};

//同时具备了保留private，又可以不使用友元的方式去进行重载
Complex operator + (const Complex & lhs,const Complex & rhs)
{
	Complex tmp(lhs);//先创建临时对象
	tmp += rhs;//通过临时对象调用运算符函数
	return tmp;
}

int main(void)
{
	Complex c1(1.0, 2.0);
	c1.display();
	Complex c2(3.0, -4.0);
	c2.display();
	Complex ret  = c1 + c2;
	//希望加法操作也能适用于自定义类型
	ret.display();
}
