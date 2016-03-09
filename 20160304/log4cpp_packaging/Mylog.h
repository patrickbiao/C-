 ///
 /// @file    Mylog.h
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-09 19:38:21
 ///
//定义头文件时，要在前面使用宏
#ifndef __MYLOG_H__
#define __MYLOG_H__
#include <iostream>
#include <log4cpp/Category.hh>
#include <sstream>
#include <string>
using std::string;

//由于输出日志只需要一个这样的对象就行了
//所以将其做成单例模式，这样在哪里使用
//该类都可以;单例模式相当于全局变量，只需
//引入该头文件就可以访问这个对象
class Mylog
{
public:
	static Mylog * getInstance();//3.创建静态的成员函数

	void fatal(const char * msg);//fatal级别
	void debug(const char * msg);
	void info(const char * msg);
	void error(const char * msg);//输出error信息

private:
	Mylog();//1.将构造函数放在private区域

private:
	log4cpp::Category & _cat;
	static Mylog * _pInstance;//2.创建一个静态的类指针
	//静态数据成员了初始化在类之外
};

#ifdef _MYLOG4CPP_//在定义宏的地方执行get
Mylog * plog = Mylog::getInstance();
#else//没定义宏的地方，就只是一个外部变量
extern Mylog * plog;
#endif

inline string int2str(int num)
{
	std::ostringstream oss;
	oss << num;//将num写到字符串中
	return oss.str();
}

#define postfix(msg) string(msg).append("{").append(__FILE__)\
			   .append("-").append(__func__)\
			   .append("-").append(int2str(__LINE__))\
			   .append("}").c_str()//最后传的是const char*
	//先创建对象msg，再调用append函数,由于append返回字符串，
	//故可以再调用
	

//将这个宏用后面的字符串替换
#define	LOG_FATAL(msg) plog->fatal(postfix(msg))
#define LOG_ERROR(msg) plog->error(postfix(msg))
#define LOG_INFO(msg)  plog->info(postfix(msg))
#define LOG_DEBUG(msg) plog->debug(postfix(msg))

#endif
