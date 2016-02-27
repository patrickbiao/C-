 ///
 /// @file    overload.c
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 12:48:35
 ///
 
#include <iostream>

//#include <stdio.h>
using std::cout;
using std::endl;

/*C++支持函数重载，其实现原理是：名字改编（name managling）.
 * 同名函数根据其参数的类型，个数，顺序进行改编*/
int add(int a,int b)
{
	return a+b;
}

int add(int a,int b,int c)
{
	return a+b+c; 
}

double add(double a,double b)
{
	return a+b;
}

int main()
{
	int a=3,b=4,c=5;
	cout << "a+b=" << add(3,4) << endl;
	cout << "a+b+c=" << add(3,4,5) << endl;
	return 0;	
//	printf("a+b = %d\n",add(3,4));
}
