 ///
 /// @file    class_string.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-01 10:17:35
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{	
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();
	void printf();
private:
	char * _pstr;
};

String::String()
//: _pstr(NULL)
//这样用得在printf()判断是否为空，
//为保持程序一致性，不这样用
{//因为在delete中，一般是delete一个数组
 //为了保持代码的一致性，故在空字符串时，也申请一个字节的空间
 #if 1
	cout << "String()" << endl;
	_pstr = new char [1];
	_pstr[0] = '\0';	
#endif
}

String::String(const char *pstr)
{	//使用打印跟踪的方式进行调试,看运行到哪了
	cout << "String(const char *pstr)" << endl;
	_pstr = new char[strlen(pstr)+1];//开辟的空间大小由pstr决定,后面一字节用来放‘\0’
	strcpy(_pstr,pstr);
}

String::String(const String & rhs)
{
	cout << "String(const String & rhs)" << endl;
	_pstr = new char [strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
}

String & String::operator = (const String & rhs)
{
	cout << "operator = (const String & rhs)" << endl;
	if(this == &rhs)//1自复制(就没必要重新开辟空间)
	{
		return *this;
	}

	delete [] _pstr;//2.释放现有已申请的堆空间(删除当前空间，再创建)
	_pstr = new char[strlen(rhs._pstr)+1];//3.申请空间进行复制
	strcpy(_pstr,rhs._pstr);
	return *this;
}

String::~String()
{
	delete [] _pstr;
}
void String::printf()//在函数名前加类名和作用域
{
	cout << "The string is :" << _pstr << endl;
}

int main(void)
{
	String s1;
	s1.printf();

	String s2 = "hello world";
	String s3 = "wangdao";
	s2.printf();
	s3.printf();
	s2 = s3;	
	s2.printf();
	String s4 = s2;
	return 0;
}
