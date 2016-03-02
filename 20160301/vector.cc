 ///
 /// @file    vector.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-02 22:00:17
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

void printfVector(std::vector<int> & vecInt)//传他的引用
{
	cout << "vector's size :" << vecInt.size() << endl;//类似于strlen
	cout << "vector's capacity:" << vecInt.capacity() << endl;
}
int main(void)
{
	std::vector<int> vecInt;//整体是一个类名，尖括号为数组存放的类型
	vecInt.reserve(100);//先开好一个固定数量的空间
	printfVector(vecInt);
	vecInt.push_back(1);//表示在尾部进行添加
	printfVector(vecInt);
	vecInt.push_back(2);
	printfVector(vecInt);
	vecInt.push_back(3);
	printfVector(vecInt);
	vecInt.push_back(4);
	printfVector(vecInt);
	vecInt.push_back(5);
	printfVector(vecInt);
	vecInt.push_back(6);
	printfVector(vecInt);

	//通过迭代器遍历数组
	std::vector<int>::iterator it = vecInt.begin();
	for(;it != vecInt.end();++it)//从第一个位置开始一点点遍历
	{
		cout << *it << endl;//通过指针去访问数据
	}

	for(int idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << endl;//因为是数组，通过下标法访问
	}
	
	//C++ 11的方式
	//编译时需要加编译选项 -std=c++11
	for(auto elem : vecInt)//自动遍历容器，数据都用elem来存储
	{
		cout << elem << endl;
		
	}
	return 0;
}
