// city.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

// 把字符串s按照delim分割成字符串数组
vector<string> split(const string& s, const string& delim)
{
	vector<string> elems;
	size_t pos = 0;
	size_t len = s.length();
	size_t delim_len = delim.length();
	if (delim_len == 0) return elems;
	while (pos < len)
	{
		int find_pos = s.find(delim, pos);
		if (find_pos < 0)
		{
			elems.push_back(s.substr(pos, len - pos));
			break;
		}
		elems.push_back(s.substr(pos, find_pos - pos));
		pos = find_pos + delim_len;
	}
	return elems;
}

//读取文件，后续改造成两个函数，分别读两个文件
void readTxt(string file) {
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	string s;
	int txtLine = 0;
	while (getline(infile, s))
	{
		//txtLine++;
		//cout << "line"; cout << txtLine << endl;
		cout << s << endl;
		vector<string> lineArr = split(s, " ");
		//目前调试输出使用
		for (auto val : lineArr)
		{
			cout << val << "," << endl;
		}
	}
	infile.close();             //关闭文件输入流 
}

int main()
{
	readTxt("config.txt");
	int row = 0, column = 0, maxDis = 0;
	vector<int> buildings;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
