// heapSort.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������Ϊ�˷������������Ӧ��������е�0��Ϊ��
//����������ȫ�����������ϵ��´����ұ��Ϊ1,2,3,4,5......
//

#include "stdafx.h"
#include<stdlib.h>
#include<algorithm>
void HeapSort(int*start, int len);
void HeapInAdjust(int*start, int start_index, int last_index);//�����󶥶ѵĲ��ֺ���
using namespace std;

int main()
{

	int arr[] = {2,334,5,2,3,1,352,46,32,34,246,23341,23,15,32,54,376534,52,34,123,4};
	HeapSort(arr,21);//��0������
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

		if (big_value > top_value)//������ӽڵ�ϴ�ıȶ��㻹����ô��ֵ����ʵ�ǽ�����ֻ���ȸ�ֵ��ѭ������������һ�ν�����
		{
			start[j / 2] = big_value;
			ChangeIndex = j;
		}
		else 
			break;

	}
	start[ChangeIndex] = top_value;//����ٰ�top������Ľ�������
}

void HeapSort(int*start, int len)//lenΪ���鳤��  index=0������
{
	for (int i = (len-1)/2; i >0; --i)//����Ӵ������ڵ���С�������������ɱ�֤�ӽڵ��Ѿ��ź���
	{
		HeapInAdjust(start,i,len-1);
	}//�󶥶ѹ������

	for (int i = 1; i < len; ++i)
	{
		int temp = start[1];
		start[1] = start[len - i];
		start[len - i] = temp;
		HeapInAdjust(start, 1, len - i - 1);
	}

}