// StringPermutationAndCombination.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FUNC
void Permutation1(string aa, int cur, vector<string>& result)//��ȥ�ظ��ַ�������  ��ABC-> ABC ACB BAC BCA CBA CAB
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
void Permutation2(string aa, int cur, vector<string>& result)//ȥ�ظ��ַ�������  
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



//�������� �� ��һ���ַ�����ѡnum��Ԫ��
//�������� �� pStrΪ�ַ����� curΪ��ǰ��ָԪ�أ�numΪѡ��Ԫ�ظ����� resultΪѡ�е�
//����ֵ ��   ��
void Combination_m(string pStr,int cur, int num, vector<char> &result,vector<string>&finalresult)
{
	if (((cur>=pStr.size())&&(num!=0))||( pStr.size()<=0))
		return;
	if (num == 0) //�ݹ���ֹ����
	{
		string tmp = "";
		for (unsigned i = 0; i < result.size(); i++)
			tmp+= result[i];
		finalresult.push_back(tmp);
		return;
	}
	//ѡ�����Ԫ��
	result.push_back(pStr[cur]);
	Combination_m(pStr, cur + 1, num - 1, result, finalresult);
	result.pop_back();
	//��ѡ�����Ԫ��
	Combination_m(pStr, cur+1, num, result, finalresult);
}
//�������� �� ��һ���ַ��������
//�������� �� pStrΪ�ַ���
//����ֵ ��   ��
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

