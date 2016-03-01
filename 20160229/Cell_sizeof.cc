 ///
 /// @file    Cell_sizeof.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-01 12:47:55
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Cell
{
	
};

class CellX
{
//public:

private:
	int a;//4
	char b;//1
	float c;//4
	double d;//8
	short e[5];//10
	char & f;//引用，malloc一个指针的大小，64位8个字节
	double & g;//8
	static int h;//4,由于不入栈且不入堆（常量区），所以不占用存储空间
};

int main(void)
{
	Cell c1;
	cout << sizeof(Cell) << endl;
	Cell c2;//一个字节大小只是为了区分c1和c2
	//是不同对象，所以还是会开辟一个字节的空间
//	CellX cx1;
	cout << sizeof(CellX) << endl;
}
