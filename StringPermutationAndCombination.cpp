// StringPermutationAndCombination.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FUNC
void Permutation1(string aa, int cur, vector<string>& result)//不去重复字符的排列  如ABC-> ABC ACB BAC BCA CBA CAB
{														     //ABB-> ABB ABB BAB BBA BBA BAB 
	if (cur == aa.size() - 1)
		result.push_back(aa);

	for (int i = cur; i < aa.size(); ++i)
	{
		swap(aa[i], aa[cur]);
		Permutation1(aa, cur + 1, result);
		swap(aa[i], aa[cur]);
	}
}

bool IsSwap(string &aa, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		if (aa[i] == aa[end])
			return false;
	}
	return true;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FUNC2
void Permutation2(string aa, int cur, vector<string>& result)//去重复字符的排列  
{														     //ABB-> ABB BAB BBA   
	if (cur == aa.size() - 1)
		result.push_back(aa);

	for (int i = cur; i < aa.size(); ++i)
	{
		if (IsSwap(aa, cur, i))
		{
			swap(aa[i], aa[cur]);
			Permutation2(aa, cur + 1, result);
			swap(aa[i], aa[cur]);
		}
	}
}



//函数功能 ： 从一个字符串中选num个元素
//函数参数 ： pStr为字符串， cur为当前所指元素，num为选的元素个数， result为选中的
//返回值 ：   无
void Combination_m(string pStr,int cur, int num, vector<char> &result,vector<string>&finalresult)
{
	if (((cur>=pStr.size())&&(num!=0))||( pStr.size()<=0))
		return;
	if (num == 0) //递归终止条件
	{
		string tmp = "";
		for (unsigned i = 0; i < result.size(); i++)
			tmp+= result[i];
		finalresult.push_back(tmp);
		return;
	}
	//选择这个元素
	result.push_back(pStr[cur]);
	Combination_m(pStr, cur + 1, num - 1, result, finalresult);
	result.pop_back();
	//不选择这个元素
	Combination_m(pStr, cur+1, num, result, finalresult);
}
//函数功能 ： 求一个字符串的组合
//函数参数 ： pStr为字符串
//返回值 ：   无
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FUNC3
void Combination(string pStr,vector<string>&finalresult)
{
	if (pStr.size()<=0)
		return;
	for (int i = 1; i <= pStr.size(); i++)
	{
		vector<char> result;
		Combination_m(pStr, 0, i, result, finalresult);
	}
}


int main(int argc, char* argv[])
{
	vector<string> tt;
	vector<string> tt2;
	vector<string> tt3;
	Permutation1("abc", 0, tt);
	Permutation2("abc", 0, tt2);

	Combination("abc",tt3);
	return 0;
}

