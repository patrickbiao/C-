 ///
 /// @file    log4cppTest.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-03 17:27:49
 ///

//引号表示从当前上当搜索有没有该文件
//尖括号直接去系统目录下找文件
#include "stdio.h"
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

int main(void)
{
//	appender->setLayout(new log4cpp::BasicLayout());//创建BasicLayout
	
	log4cpp::PatternLayout * ptnLayout = 
		new log4cpp::PatternLayout();
	ptnLayout->setConversionPattern("%d:%p %c %x: %m%n");

	log4cpp::Appender * appender = 
		new log4cpp::OstreamAppender("console",&std::cout);//通过new方式创建appender对象	
	
	appender->setLayout(ptnLayout);

	log4cpp::Category & root = log4cpp::Category::getRoot();//设置入口函数Category
	log4cpp::Category & infoCat = root.getInstance("infoCat");
//	root.setPriority(log4cpp::Priority::DEBUG);//优先级设置为debug,高于它的都会显示
	root.setPriority(log4cpp::Priority::ERROR);//优先级设置为warn
	root.setAppender(appender);
	//set完毕

	infoCat.error("system error");
	infoCat.info("system is running");
	infoCat.info("system shutdown,you can find some information in system log");
	infoCat.info("system has a fatal error,must be shutdown");
	root.error("root error");
	root.info("root infor");
	root.warn("%d + %d = %s",1,1,"two");
	log4cpp::Category::shutdown();
	return 0;


}
