 ///
 /// @file    1.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-25 18:57:34
 ///
 
#include <iostream>

using namespace std;
namespace A
{
	void dispA()
	{
		cout << "This is A" << endl;
	}
}

namespace B
{
	void dispB()
	{	
		cout << "This is B" << endl;
	}
}

int main (int argc,char **argv)
{
	B::	dispB();
	return 0;


}
