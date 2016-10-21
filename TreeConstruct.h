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


//！！！！！！！！PS  注意2种方式的端点的处理不一样，一个输入完全二叉树的表示，一个输入遍历的表示！！！！！！！！！！！！！！！！//


TreeNode* ConstructBinarySearchTree(int *data, int len);//通过队列构建二叉树，输入的是层序遍历，没有节点使用INT_MIN代替  PS:输入的是完全二叉树!所有没结点得表示出来 如：
//																		5
//														4						  2      
//											2			       INT_MIN	     5		      INT_MIN  
//								   INT_MIN    INT_MIN     INT_MIN  INT_MIN 6   7	  INT_MIN   INT_MIN
//				

TreeNode* ConstructBinarySearchTree(string input[]);//通过前序遍历构建二叉树 端点使用"#"表示，输入的是带端点的前序遍历如：
//																5
//															4		 2       前序遍历
//														2	  #	   5	#   ----------> 5 4 2 # # # 2 5 6 # # 7 # # #   
//													  #  #	   	 6   7	
//																# # # #

void CoutTreeFront(TreeNode* input);//前序遍历二叉树并使用cout输出

void CoutTreeMid(TreeNode* input);//中序遍历二叉树并使用cout输出

void CoutTreeBehind(TreeNode* input);//后序遍历二叉树并使用cout输出