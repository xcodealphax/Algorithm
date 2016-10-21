// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int>&input,int Left,int len)
{
	if (len > 2)
	{
		MergeSort(input, Left,len/2);
		MergeSort(input, Left + len / 2,len-len/2);
	}
	vector<int>tmp;
	int ll = 0, rr = 0;
	for (; (ll < len / 2) && (rr < len - len / 2); )
	{
		int data = 0;
		if (input[Left + ll]>input[Left + len / 2+rr])
		{
			data = input[Left + len / 2+rr];
			rr++;
		}
		else
		{
			data = input[Left + ll];
			ll++;
		}
		tmp.push_back(data);
	}
	for (; ll < len / 2; ++ll)
		tmp.push_back(input[Left + ll]);
	for (; rr < len - len / 2; ++rr)
		tmp.push_back(input[Left + len / 2 + rr]);

	for (int i = 0; i < len; ++i)
	{
		input[Left + i] = tmp[i];
	}
	return;
}

int main(int argc, char* argv[])
{
	vector<int> ttt;
	for (int i=0;i<5000;++i)
		ttt.push_back(rand()%23146);

	MergeSort(ttt,0,5000);

	bool charge = true;
	for (int i = 1; i < 5000; ++i)
	{
		if (ttt[i] < ttt[i - 1])
		{
			charge = false;
			break;
		}
	}
	cout << charge << endl;
	getchar();
	return 0;
}

