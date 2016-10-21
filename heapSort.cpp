// heapSort.cpp : 定义控制台应用程序的入口点。
//
//堆排序，为了方便与二叉树对应编号数组中第0号为空
//二叉树是完全二叉树，从上到下从左到右编号为1,2,3,4,5......
//

#include "stdafx.h"
#include<stdlib.h>
#include<algorithm>
void HeapSort(int*start, int len);
void HeapInAdjust(int*start, int start_index, int last_index);//构建大顶堆的部分函数
using namespace std;

int main()
{

	int arr[] = {2,334,5,2,3,1,352,46,32,34,246,23341,23,15,32,54,376534,52,34,123,4};
	HeapSort(arr,21);//第0不排序
	return 0;
}

void HeapInAdjust(int*start, int start_index, int last_index)
{
	int top_value = start[start_index];
	int ChangeIndex = start_index;
	for (int j = start_index*2; j <= last_index; j *= 2)
	{
		int big_value = 0;
		if (((j + 1) <= last_index) && (start[j + 1] > start[j]))
		{
			big_value = start[j + 1];
			j++;
		}
		else
			big_value = start[j];

		if (big_value > top_value)//如果孩子节点较大的比顶点还大，那么赋值（其实是交换，只是先赋值，循环完后再做最后一次交换）
		{
			start[j / 2] = big_value;
			ChangeIndex = j;
		}
		else 
			break;

	}
	start[ChangeIndex] = top_value;//最后再把top与后来的交换即可
}

void HeapSort(int*start, int len)//len为数组长度  index=0不排序
{
	for (int i = (len-1)/2; i >0; --i)//必须从大索引节点往小的排序，这样即可保证子节点已经排好序
	{
		HeapInAdjust(start,i,len-1);
	}//大顶堆构建完成

	for (int i = 1; i < len; ++i)
	{
		int temp = start[1];
		start[1] = start[len - i];
		start[len - i] = temp;
		HeapInAdjust(start, 1, len - i - 1);
	}

}