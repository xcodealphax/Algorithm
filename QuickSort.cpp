// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
using namespace std;

void quick_sort(int *start, int len);

int main()
{
	const int N = 87;
	int *test = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
		test[i] = rand() % 7778;

	quick_sort(test, N);

	bool result = true;
	for (int i = 1; i < N; ++i)
	{
		if (test[i - 1]>test[i])
			result = false;

		cout << test[i] << '\t';
	}
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << result << endl;
	getchar();
	exit(0);


	return 0;
}

void quick_sort(int *start, int len)//快速排序算法
{
	if (len <= 1)return;

	int *left = start;
	int *right = start + len - 1;
	while (left != right)
	{
		while (*left <= *right)
		{
			right--;
			if (left == right)break;
		}
		if (left == right)break;
		
		int temp = *left;
		*left = *right;
		*right = temp;

		while (*left <= *right)
		{
			left++;
			if (left == right)break;
		}
		if (left == right)break;

		temp = *left;
		*left = *right;
		*right = temp;
	}
	quick_sort(start, left-start);
	quick_sort(left+1, len-(left-start)-1);
}