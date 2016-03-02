 ///
 /// @file    fstream.cc
 /// @author  patrick(730557219@qq.com)
 /// @date    2016-03-02 23:28:56
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

int main(void)
{
		ifstream ifs("io1.cc");
			if(!ifs.good())
					{
								cout << "ifstream open error!" << endl;
										return -1;
											}

				
				string s;
#if 0
					while(ifs >> s)
							{
										cout << s << endl;
											}
						while(getline(ifs, s))
								{
											cout << s << endl;
												}
#endif

							vector<string> vecStr;
								string line;
									while(getline(ifs, line))
											{
														vecStr.push_back(line);
															}

										vector<string>::iterator it = vecStr.begin();
											for(; it != vecStr.end(); ++it)
													{
																cout << *it << endl;
																	}


												return 0;
}
