//
 /// @file    Mylog.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-09 20:00:10
 ///

 //如果要实现具体的一个实现文件第一条必须要包含 
//自己的头文件之后再放其它的头文件，顺序不能反
#include "Mylog.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <iostream>

//静态成员初始化,返回值为类指针
Mylog * Mylog::_pInstance = NULL;

//通过类名调用静态成员函数，返回类型指针
Mylog * Mylog::getInstance()
{
	if(_pInstance == NULL)	
	{
		_pInstance = new Mylog();
	}
	return _pInstance;
}


Mylog::Mylog()
: _cat(log4cpp::Category::getRoot().getInstance("myCat"))
//引用必须在初始化列表中初始化,通过访问get创建名字
{
	//一个PatternLayout对应一个appender,然后将appender的东西设置到pattern中
	log4cpp::PatternLayout * ptnLay1 = 
		new log4cpp::PatternLayout();
	ptnLay1->setConversionPattern("%d:%p %c %x: %m%n");
	//d-时间;c-Category名字;x-上下文信息;m-真正的信息;n-换行符
	//以上是设置的第一个PatternLayout
	
	log4cpp::PatternLayout * ptnLay2 = 
		new log4cpp::PatternLayout();
	ptnLay2->setConversionPattern("%d:%p %c %x: %m%n");

	log4cpp::OstreamAppender * appender1 = 
	new log4cpp::OstreamAppender("ostream", &std::cout);
	//第一个参数是Appender的名字,第二个是自己绑定的cout
	appender1->setLayout(ptnLay1);

	log4cpp::FileAppender * appender2 = 
		new log4cpp::FileAppender("fileAppend","wangdao.log");
	appender2->setLayout(ptnLay2);

	_cat.addAppender(appender1);
	_cat.addAppender(appender2);
	_cat.setPriority(log4cpp::Priority::DEBUG);//优先级设置
	
	//以上初始化完成						
}

void Mylog::fatal(const char * msg)
{
	_cat.fatal(msg);
}						

void Mylog::debug(const char * msg)
{
	_cat.debug(msg);
}				

void Mylog::info(const char * msg)
{
	_cat.info(msg);
}		

void Mylog::error(const char * msg)
{
	_cat.error(msg);
}									
