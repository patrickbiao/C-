 ///
 /// @file    namespace2.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-25 20:18:37
 ///
 
#include <iostream>

using namespace std;

extern int num = 0;

namespace B
{
	int num = 2;
}

namespace A
{
	int num = 1;
	void dispA()
	{
		int num =3;
		cout <<"dispA函数中的num："<<num <<endl;
		cout << "A中的num:" << A::num << endl;
		cout << "B中的num:" << B::num << endl;
		cout << "外部的num:" << ::num << endl;
	}
}

int main()
{
	A::dispA();
	return 0;
}
