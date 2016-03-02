 ///
 /// @file    operator_new.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-02 20:10:28
 ///
 
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class Student
{
public:
	Student()
	{
		cout << "Student" << endl;
	}

	~Student()
	{
		cout << "~Student" << endl;
	}

	static void * operator new(size_t sz)
	{
		cout << "operator new()" << endl;
		void * pRet = malloc(sz);
		return pRet;
	}

	static void operator delete(void * pRet)
	{
		cout << "operator delete()" << endl;
		free(pRet);
	}
private:
	int _Id;
	char name[20];
};

int main(void)
{
	Student * pStu = new Student;//创建一个堆空间对象
	delete pStu;
	return 0;
}
