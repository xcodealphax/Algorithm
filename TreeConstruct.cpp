// TreeTestCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"TreeConstruct.h"
using namespace std;


class Base
{
public:
	int a;
protected:
	int b;
};

class D : Base
{
	void test(){}

protected:
	int c;
};



int main(int argc, char* argv[])
{		

	int arr[7] = { 1, 2, 3, INT_MIN, INT_MIN, 8, INT_MIN };
	TreeNode* tree_root=ConstructBinarySearchTree(arr, 7);
	CoutTreeFront(tree_root);
	cout << endl;
	CoutTreeMid(tree_root);
	cout << endl;
	CoutTreeBehind(tree_root);
	cout << endl;
	cout << "finish" << endl;


	string arr2[] = {"1","2","#","#","3","8","#","#","#"};
	TreeNode* tree_root2 = ConstructBinarySearchTree(arr2);
	CoutTreeFront(tree_root2);
	cout << endl;
	CoutTreeMid(tree_root2);
	cout << endl;
	CoutTreeBehind(tree_root2);
	cout << endl;
	cout << "finish" << endl;

	getchar();
	exit(0);
	return 0;
}

TreeNode* ConstructBinarySearchTree(int *data, int len)//通过栈构建二叉树，输入的是层序遍历，没有节点使用INT_MIN代替
{
	if (len == 0)return NULL;
	int Cnt = 0;
	deque<TreeNode*> Last_data;
	TreeNode* root=NULL;
	TreeNode* root_temp;
	TreeNode* node_temp;
	while (Cnt<len)
	{
		if (Last_data.size() == 0)
		{
			root = new TreeNode(data[0]);
			Last_data.push_back(root);
			Cnt++;
			continue;
		}

		int deq_size = Last_data.size();
		for (int i = 0; i < deq_size; ++i)//每次把队列里面的节点双倍化
		{
			root_temp = (Last_data[0]);//读出根节点
			Last_data.pop_front();

			if (Cnt >= len)return root;
			if (root_temp != NULL)
			{
				if (data[Cnt] != INT_MIN)
				{
					node_temp = new TreeNode(data[Cnt]);
					root_temp->left = node_temp;
					Last_data.push_back(node_temp);
				}
				else
				{
					Last_data.push_back(NULL);
				}
			}
			else
				Last_data.push_back(NULL);
			Cnt++;

			if (Cnt >= len)return root;
			if (root_temp != NULL)
			{
				if (data[Cnt] != INT_MIN)
				{
					node_temp = new TreeNode(data[Cnt]);
					root_temp->right = node_temp;
					Last_data.push_back(node_temp);
				}
				else
				{
					Last_data.push_back(NULL);
				}
			}
			else 
				Last_data.push_back(NULL);
			Cnt++;
		}
	}


	return root;
}


TreeNode* CBST_Front(TreeNode** LinkPtr, string data[], int &Index)//需要改变的是指针的值，因此要指向指针的指针
{
	if (data[Index][0] == '#')
		*LinkPtr = NULL;
	else
	{
		int num = atoi(data[Index].c_str());//假设数据是int类型
		TreeNode* tmp = new TreeNode(num);
		*LinkPtr = tmp;

		CBST_Front(&((*LinkPtr)->left), data, ++Index);
		CBST_Front(&((*LinkPtr)->right), data, ++Index);
	}
	return *LinkPtr;
}

TreeNode* ConstructBinarySearchTree(string input[])//通过前序遍历构建二叉树 端点使用"#"表示，输入的是带端点的前序遍历
{
	TreeNode* root;
	int index = 0; //数据游标值
	root = CBST_Front(&root, input, index);
	return root;
}

void CoutTreeFront(TreeNode* input)//前序遍历二叉树并使用cout输出
{
	if (input!=NULL)
		cout << input->val << '\t';

	if (input->left != NULL)
		CoutTreeFront(input->left);

	if (input->right != NULL)
		CoutTreeFront(input->right);
}

void CoutTreeMid(TreeNode* input)//中序遍历二叉树并使用cout输出
{
	if (input->left != NULL)
		CoutTreeMid(input->left);

	if (input != NULL)
		cout << input->val << '\t';

	if (input->right != NULL)
		CoutTreeMid(input->right);
}

void CoutTreeBehind(TreeNode* input)//后序遍历二叉树并使用cout输出
{
	if (input->left != NULL)
		CoutTreeBehind(input->left);

	if (input->right != NULL)
		CoutTreeBehind(input->right);

	if (input != NULL)
		cout << input->val << '\t';
}