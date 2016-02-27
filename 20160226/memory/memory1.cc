 ///
 /// @file    memory1.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 15:58:35
 ///
 
#include <iostream>
#include <string.h>
#include <stdio.h>

int a = 0;//全局变量区
char * p1;//全局变量区

const int d =1;//文字常量区
int main()
{
	int b;//栈区
	char s[] = "123456";//s位于栈区
	char * p2;//p2位于栈区，指向的区域位于文字常量区
	char * p3 = "123456";//p3位于栈区，但指向的字符串位于文字常量区（即只读段）
	static int c = 0;//全局变量区
	p1 = new char [10];//p1位于栈区，p1指向的对象位于堆
	strcpy(p1,"123456");
	const int e =2;	//尽管是常量，但放在栈区，原因是生命周期不一样
	
	printf("&a = %x\n",&a);
	printf("&p1 = %x\n",&p1);
	printf("&c = %x\n",&c);
	printf("p1 = %x\n",p1);
	printf("&b = %x\n",&b);
	printf("s = %x\n",s);
	printf("&s = %x\n",&s);
	printf("&p2 = %x\n",&p2);
	printf("p2 = %x\n",p2);
	printf("&p3 = %x\n",&p3);
	printf("p3 = %x\n",p3);
	printf("&d = %x\n",&d);
	printf("&e = %x\n",&e);
	return 0;
}
