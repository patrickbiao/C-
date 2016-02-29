 ///
 /// @file    nullpointcall.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-29 21:16:23
 ///
 
#include <iostream>

using std::cout;
using std::endl;

//对于非静态的成员函数，第一个参数是隐藏的this指针
//对于静态成员函数而言，没有this指针

class NullPointerCall//空指针调用
{
public:
	static void test1();
	void test2();
	void test3(int ix);
	void test4();	
private:
	static int _istatic;
	int _ix;
};

int NullPointerCall::_istatic = 0;

void NullPointerCall::test1()//静态成员是没有this指针的
{//只要给test1作用域，它就知道对象在哪
	cout << "test1() static:" << _istatic << endl;
}

void NullPointerCall::test2()//非静态的，有this指针
{
	cout << "test2()" << endl;//没有通过this指针去访问
	//数据，所以没报错
}

void NullPointerCall::test3(int ix)
{//这里的thsi指针也没有对数据进行操作(直接将形参ix拿出来)
//，所以没coredump
	cout << "test3()" << ix << endl;
}

void NullPointerCall::test4()
{//通过this去调，由于这时this指针被赋值为空
	cout << "test4()" << this->_ix << endl;
}

int main()
{
	NullPointerCall * npc = NULL;
	npc->test1();
	npc->test2();
	npc->test3(3);
	npc->test4();
}
