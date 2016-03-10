 ///
 /// @file    complex.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-10 22:08:04
 ///
 
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Complex
{
	//返回ostream的输出流
	friend std::ostream & operator<<(std::ostream &, const Complex & rhs);
	friend std::istream & operator>>(std::istream &, Complex & rhs);
	//后一个操作数就不能用const了，因为输入要修改其值
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex (double,double)" << endl;
	}
private:
//通过语法规则表达语义：该对象不能进行复制。流对象就是这样的原理
//	Complex(const Complex &);//复制构造函数
//	Complex & operator=(const Complex &)//赋值运算符函数
	double _dreal;
	double _dimag;
};

//输入输出运算符的重载必须以友元函数的形式进行重载，
//不能是成员函数，因为他们要求第一个参数是流类型
//流对象os不能进行复制，所以必须返回对象，不然会调用复制构造函数
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs._dreal;
	if(rhs._dimag > 0)
		os << " + " << rhs._dimag << "i";
	else if(rhs._dimag < 0)
		os << " - " << (-1) * rhs._dimag << "i";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	is >> rhs._dreal;	
	while(is.get() != '*')//通过get获取一个字符
	{}
	is >> rhs._dimag;
	return is;
}
int main(void)
{
	Complex c1(3,4);
	cout << c1 << endl;//对类的输出与输出普通类型是一样的了

	Complex c3(c1);
	
	cin >> c3;
	cout << c3;
}
