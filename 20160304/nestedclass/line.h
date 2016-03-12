 ///
 /// @file    line.h
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-12 22:34:32
 ///
 
#ifndef __LINE_H__
#define __LINE_H__

class Line
{
class LineImpl;//将以下函数的具体在内部类中实现 
public:
	Line(int, int, int, int);
	~Line();//因为new了堆空间，需要释放
	void printfLine();
private:
	LineImpl * _pImp;
};

#endif
