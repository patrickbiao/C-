 ///
 /// @file    namespace.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-25 19:39:20
 ///
 
#include <iostream>

using namespace std;

		void dispA()
				{
							cout<<"This is A"<<endl;	
								}
		void dispB()
				{
dispA();		//名称空间A中的dispA函数
									cout<<"This is B"<<endl;	
										}

int main()
{
		dispB();	//名称空间B中的dispB函数
			return 0;
}


