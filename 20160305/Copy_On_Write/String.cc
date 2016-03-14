 ///
 /// @file    String.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-13 23:22:52
 ///
 
#include <iostream>
#include <string.h>
#include <stdio.h>

using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();
	
	char & operator[](int idx);//

	int getSize();
	
	int use_count();

	const char * c_str() const
	{
		return _pstr;
	}
private:
	char * _pstr;
};

String::String()
: _pstr(new char[2])//多创建一个空间
{
	cout << "String()" << endl;
	_pstr[1] = 1;//引用计初始值为1
}

String::String(const char * pstr)//有参构造函数
{
	cout << "String(const char * pstr)" << endl;
	int len = strlen(pstr);
	_pstr = new char[len+2];//多创建一个空间
	strcpy(_pstr,pstr);
	_pstr[len + 1] = 1;//引用计初始值为1，在字符串后面加上
}

String::String(const String & rhs)//复制构造函数
: _pstr(rhs._pstr)//浅拷贝，指向同一个堆空间
{
	cout << "String(const String & rhs)" << endl;
	++ _pstr[getSize() + 1];//引用计数加1
}

String & String::operator=(const String & rhs)
{
	cout << "operator=(const String & rhs)" << endl;
	if(this == &rhs)//this指针，考虑自复制
		return * this;
	//_pstr = rhs._pstr;这时_pstr指向了rhs._pstr的堆空间，所以
	//需要自减，当减后为零时，将_pstr的内容删除，让其指向rhs._pstr
	//中的内容,即变成普通意义上的赋值
	if(-- _pstr[getSize() + 1] == 0)//非自复制，将引用计数减1
		delete [] _pstr;

	_pstr = rhs._pstr;
	++_pstr[getSize()+1];

	return * this;

}

String::~String()
{
	if(0 == --_pstr[getSize() + 1])
	{//如果等于零才执行析构，即将其删除不然只作减1

		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

int String::getSize()
{
	return strlen(_pstr);
}

int String::use_count()
{
	return _pstr[getSize() + 1];
}

int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3;
	s3 = s2;
	cout << "s1's use_count is " << s1.use_count() << endl;
	cout << "s2's use_coutt is " << s2.use_count() << endl;
	printf("s1's address = %p\n",s1.c_str());
	printf("s2's address = %p\n",s2.c_str());
	printf("s3's address = %p\n",s3.c_str());
}
