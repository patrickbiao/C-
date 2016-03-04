 ///
 /// @file    stringstream.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-03 16:22:28
 ///
 
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

string int2string(int ival)
{
	ostringstream oss;
	oss << ival;
	return oss.str();
}

//字符串的格式化：
//对于字符串输入流而言，可以把字符串转成特定的类型
//对于字符串输出流而言，可以把特定的类型转成字符串

int main(void)
{
	int ival = 512;
	int ival2 = 1024;
	stringstream ss;//==> snprintf();
	ss << "ival = " << ival << ", ival2 = " << ival2 << endl;
	string s = ss.str();
//	cout << ss << endl;
	cout << s << endl << endl;
	cout << "int2string " << int2string(ival) << endl;

	int a,b;
	string s1;
	string s2;
//	istringstream iss(s);
	ss >> s1 >> a >> s2 >> b;

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
