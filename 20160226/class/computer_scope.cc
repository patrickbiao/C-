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
	void setBrand(char * brand);
	void setPrice (float fprice);
	void printf();
private:
	char _brand[20];//类的成员变量用m_ or _
	float _price;
};

//类之外实现成员函数
void Computer::setBrand(char * brand)
{
	strcpy(_brand,brand);		
}

void Computer::setPrice(float fprice)
{
	_price = fprice;
}

void Computer::printf()
{
	cout << "品牌：" <<  _brand << endl;
	cout << "价格：" <<  _price << endl;
}

int main(void)
{
	int a;//也可以将a看成一个int型的对象
	Computer pcl;//创建一个类的实例化：Computer为类型,pcl为实例,只有实例化之后系统才为对象分配存储空间
	//pcl._fprice = 10;//信息隐藏，不能在类外使用私有成员
	pcl.setPrice(5000);
	pcl.setBrand("Dell");
	pcl.printf();
	//pcl.printf();//将其移到私有函数中，类外不能使用它
	return 0;
}
