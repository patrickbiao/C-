 ///
 /// @file    testMylog.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-09 21:15:24
 ///
 
 //一个.c文件代表一个模块，由于在头文件中定义了prog
 //而两个.c(即两个模块)调用时，会出现重复定义
#define _MYLOG4CPP_//定义这个宏，才执行plog的定义_
#include "Mylog.h"
#include <iostream>
#include <string>//要进行字符串拼接
#include <sstream>

using std::cout;
using std::endl;
using std::string;


int main(void)
{
	//Mylog * plog = Mylog::getInstance();
#if 0
	plog->fatal("system core dump");
	plog->error("system error");
	plog->info("system info");
	plog->debug("system debug");
#endif

	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __func__<< endl;
	cout << endl;
	//通过以上三个宏进行自定义
	
	LOG_FATAL("system core dump");
	LOG_ERROR("system error");
	LOG_INFO("system info");
	LOG_DEBUG("system debug");
	LOG_FATAL("system");

	return 0;
}
