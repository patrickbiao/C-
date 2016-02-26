 ///
 /// @file    const.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-25 23:38:01
 ///
 
#include <iostream>

using std::cout;
using std::endl;

#define MAX 100

int test()
{
	const int a = 3;
	cout << MAX <<endl;
	cout << "a=" << a << endl;
	//a = 10;
	//const int b;
	int const  c = 4;
}

int main()
{
	int a=3;
	int *pa=&a;
	*pa = 4;

	int *pp;
	const int *pb = &a;
	int d =10;
//	*pb=5;
}
