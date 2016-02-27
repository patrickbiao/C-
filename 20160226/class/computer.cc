 ///
 /// @file    computer.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-02-26 17:06:10
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::endl;

class Computer//新定义了Computer这个数据类型
{
public://对外提供接口
	void setBrand(char * brand)
	{
		strcpy(_brand,brand);
		printf();//在类里边使用私有成员函数,调用时直接将函数名拿过来就行，不需要在前面加void
	}
	void setPrice (float fprice)
	{
		_price = fprice;
	}
private:
	void printf()
	{
		cout << "品牌：" << _brand << endl;//在类里面使用私有的成员数据
		cout << "价格：" << _price << endl;
	}
	char _brand[20];//类的成员变量用m_ or _
	float _price;
};

int main(void)
{
	int a;//也可以将a看成一个int型的对象
	Computer pcl;//创建一个类的实例化：Computer为类型,pcl为实例
	//pcl._fprice = 10;//信息隐藏，不能在类外使用私有成员
	pcl.setPrice(5000);
	pcl.setBrand("Dell");
	//pcl.printf();//将其移到私有函数中，类外不能使用它
	return 0;
}
