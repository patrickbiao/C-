 ///
 /// @file    WordStatic.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-06 20:32:34
 ///
 
#include <iostream>
#include <fstream>//文件输入输出流
#include <string>
#include <vector>
#include <algorithm>//cppreference算法库

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Record//每条记录中包含的东西（效果与类一样）
{
	string word;//单词
	int freq;//词频
};

//定义一个比较器函数,传递左右操作数
//用const则不能修改Record中的成员
bool recordCompare(const Record & lhs,const Record & rhs)
{
	if(lhs.word < rhs.word)//指定根据string 还是根据freq进行排序
		return true;
	else 
		return false;
}

class WordStatic
{
public:
	WordStatic();//用构造函数对vector的Capacity进行初始化
	void readFile(const string & filename);
	//也可以用string filename,但这样会进行复制，效率不高,尽量用引用
	void writeFile(const string & filename);
private:
	vector<Record> _dict;
	//vector底层会做内存的管理
	//尖括号中是存放的类型(任意的),后面是名字
};

WordStatic::WordStatic()
{
	_dict.reserve(10000);//初始化容器的容量，超过一万时会自己扩容
}

//该函数执行完，不仅统计，而且排序
void WordStatic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());//创建一个输入流
	if(!ifs.good())//创建失败
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string word;//进行读取
	while(ifs >> word)//读完放在word中
	{
		vector<Record>::iterator it;
		for(it = _dict.begin(); it != _dict.end(); ++it )
		{//通过迭代器查找是否与指定的word相等
		 //string可以直接通过等于号来判断
			if(it->word == word)
			{
				++(it->freq);
				break;//退出遍历
			}
		}
		
		if(it == _dict.end())//遍历完词典没发现word
		{
			Record record;//创建record	
			record.word = word;
			record.freq = 1;
			_dict.push_back(record);
		}
	}
	ifs.close();

	std::sort(_dict.begin(),_dict.end(), recordCompare);//最后传递比较器名字
}

void WordStatic::writeFile(const string & filename)
{//经过该函数，将结果保存到filename中去
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout << "ofstream open errer!" << endl;
		return;
	}

	for(auto & elem : _dict)//每次输出都要对容器_dict进行遍历(加引用是直接访问)
	{
		ofs << elem.word << ' ' << elem.freq << endl; //使用ofs输出到文件中去
	}


}	
int main(void)
{
	WordStatic ws;
	ws.readFile("The Holy Bible.txt");//传文件名
	ws.writeFile("dict.dat");//往文件dict.dat中写

	return 0;
}
