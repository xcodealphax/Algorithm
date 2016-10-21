#include<iostream>
#include<stdlib.h>
#include<deque>
#include<map>
using namespace std;
class TreeNode
{
public:
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
	TreeNode() :val(0), left(NULL), right(NULL){}
};


//����������������PS  ע��2�ַ�ʽ�Ķ˵�Ĵ���һ����һ��������ȫ�������ı�ʾ��һ����������ı�ʾ��������������������������������//


TreeNode* ConstructBinarySearchTree(int *data, int len);//ͨ�����й�����������������ǲ��������û�нڵ�ʹ��INT_MIN����  PS:���������ȫ������!����û���ñ�ʾ���� �磺
//																		5
//														4						  2      
//											2			       INT_MIN	     5		      INT_MIN  
//								   INT_MIN    INT_MIN     INT_MIN  INT_MIN 6   7	  INT_MIN   INT_MIN
//				

TreeNode* ConstructBinarySearchTree(string input[]);//ͨ��ǰ��������������� �˵�ʹ��"#"��ʾ��������Ǵ��˵��ǰ������磺
//																5
//															4		 2       ǰ�����
//														2	  #	   5	#   ----------> 5 4 2 # # # 2 5 6 # # 7 # # #   
//													  #  #	   	 6   7	
//																# # # #

void CoutTreeFront(TreeNode* input);//ǰ�������������ʹ��cout���

void CoutTreeMid(TreeNode* input);//���������������ʹ��cout���

void CoutTreeBehind(TreeNode* input);//���������������ʹ��cout���