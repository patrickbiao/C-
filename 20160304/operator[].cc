 ///
 /// @file    operator[].cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-10 21:28:58
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class CharArr
{
public:
	CharArr(int sz);//传一个参数
	~CharArr();

	int getLength();//获取长度的函数

	char & operator[](int idx);//传一个idx过来
	//返回的是下面char*指针指向的堆空间中的一个字符
	//即这个字符本身是存在，所以能返回字符的引用。而不能
	//返回一个对象，因为会进行复制
	
	//以上是类的接口,下面实现
private:
	int _ilen;
	char * _pstr;
};

CharArr::CharArr(int sz)
: _ilen(sz)
, _pstr(new char[_ilen])
{
	cout << "CharArr()" << endl;
}

CharArr::~CharArr()
{
	delete [] _pstr;
	cout << "~CharArr()" << endl;
}

int CharArr::getLength()
{	return _ilen;}

char & CharArr::operator[](int idx)
{
//	cout << "operator[]()" << endl;
	static char nullchar = '\0';
	if(idx < _ilen && idx >=0)
	{
		return _pstr[idx];//获取该位置的数据
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

int main(void)
{
	char * pstr = "hello ,world";
	CharArr ca(strlen(pstr)+1);

	for(int idx = 0; idx != (strlen(pstr)+1); ++idx)
	{//通过对象名使用下标运算符,类似于数组的使用方式
	 //每执行一次，都会去调用下标运算符
		ca[idx] = pstr[idx];
	}

	for(int idx = 0; idx != ca.getLength(); ++idx)
	{
		cout << ca[idx] << " ";
	}
	cout << endl;
}
