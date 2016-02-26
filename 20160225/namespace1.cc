 //
 /// @file    namespace1.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-25 20:05:40
 ///
 
#include <iostream>
using namespace std;
namespace A
{
	int num = 0;
}

void disp()
{
	using A::num;
	cout<<num<<endl;
}

int main()
{
	disp();
	return 0;
}
