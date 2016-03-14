 ///
 /// @file    string.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-13 22:30:20
 ///
 
#include <iostream>
#include <string>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s1 = "hello,world";
	string s2 = s1;
	string s3 = "wangdao";
	string s4 = s3;

	cout << "s1's size = " << sizeof(s1) << endl;
	printf("s1's address = %p\n",s1.c_str());\
	cout << s1 << endl;
	cout << "s2's size = " << sizeof(s2) << endl;
	printf("s2's address = %p\n",s2.c_str());
	cout << s2 << endl;
	cout << "s3's size = " << sizeof(s3) << endl;
	printf("s3's address = %p\n",s3.c_str());
	printf("s4's address = %p\n",s4.c_str());
	cout << "修改之后：" << endl;
	s4[0] = 'H';
	cout << "s1's size = " << sizeof(s1) << endl;
	printf("s1's address = %p\n",s1.c_str());\
	cout << s1 << endl;
	cout << "s2's size = " << sizeof(s2) << endl;
	printf("s2's address = %p\n",s2.c_str());
	cout << s2 << endl;
	printf("s4's address = %p\n",s4.c_str()); 
	cout << s4 << endl;
}
