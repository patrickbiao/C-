 ///
 /// @file    overload.c
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 12:48:35
 ///
 
//#include <iostream>

#include <stdio.h>

int add(int a,int b)
{
	return a+b;
}

int add1(int a,int b,int c)
{
	return a+b+c; 
}

int main()
{
	printf("a+b = %d\n",add(3,4));
}
