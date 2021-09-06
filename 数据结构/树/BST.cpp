#include<iostream>
#include <climits>
using namespace std;
#define DataType int 

class BSTreeNode
{
	DataType data;
	BSTreeNode* left;
	BSTreeNode* right;
public:
	BSTreeNode()
	{
		data = INT_MIN;
		left = NULL;
		right = NULL;
	}
	BSTreeNode(DataType& d) :data(d), left(NULL), right(NULL) {}
	DataType GetData() const
	{
		return data;
	}
	void SetData(const DataType& d)
	{
		data = d;
	}
    
	BSTreeNode* GetLeft()
	{
		return left;
	}
	BSTreeNode* GetRight()
	{
		return right;
	}
	void SetLeft(BSTreeNode*& newLeft)
	{
		left = newLeft;
	}
	void SetRight(BSTreeNode*& newRight)
	{
		right = newRight;
	}
};

void CreateBSTree(BSTreeNode*& treeRoot)
{
	cout << "输入一串数字以空格分隔创建搜索二叉树：" << endl;
	DataType tData;
	while (cin >> tData)
	{
		//声明临时节点并把数据放进去，注意不能delete
		BSTreeNode* newNode = new BSTreeNode(tData);
		//树没有根结点的情况
		if (treeRoot == NULL)
		{
			treeRoot = newNode;
		}
		//树存在根节点
		else
		{
			//声明移动指针
			BSTreeNode* pTemp = treeRoot;
			//找到插入的位置才退出
			while (true)
			{
				//输入的数小于该节点的值
				if (tData < pTemp->GetData())
				{
					//左孩子为空，则新的节点为左孩子
					if (pTemp->GetLeft() == NULL)
					{
						pTemp->SetLeft(newNode);
						break;
					}
					//左孩子不为空，p指针移动为左孩子
					else
					{
						pTemp = pTemp->GetLeft();
					}
				}
				//输入的数不小于该节点的值
				else
				{
					//右孩子为空，则新的节点为右孩子
					if (pTemp->GetRight() == NULL)
					{
						pTemp->SetRight(newNode);
						break;
					}
					//右孩子不为空，p指针移动为右孩子
					else
					{
						pTemp = pTemp->GetRight();
					}
				}
			}
		}
		//判断是否输入结束
		if (cin.get() == '\n')
			break;
	}
}
//遍历顺序：根左右
void PreOrder(BSTreeNode* everyTreeNode)
{
	if (everyTreeNode)
	{
		cout << everyTreeNode->GetData() << " ";
		PreOrder(everyTreeNode->GetLeft());
		PreOrder(everyTreeNode->GetRight());
	}
}
//遍历顺序：左根右
void InOder(BSTreeNode* everyTreeNode)
{
	if (everyTreeNode)
	{
		InOder(everyTreeNode->GetLeft());
		cout << everyTreeNode->GetData() << " ";
		InOder(everyTreeNode->GetRight());
	}
}
//遍历顺序：左右根
void PostOrder(BSTreeNode* everyTreeNode)
{
	if (everyTreeNode)
	{
		PostOrder(everyTreeNode->GetLeft());
		PostOrder(everyTreeNode->GetRight());
		cout << everyTreeNode->GetData() << " ";
	}
}

int main()
{
	//声明树的根节点
	BSTreeNode* tree = NULL;

	//创建二叉搜索树
	CreateBSTree(tree);

	cout << endl << "先序递归遍历二叉树" << endl;
	PreOrder(tree);
	cout << endl << "中序递归遍历二叉树" << endl;
	InOder(tree);
	cout << endl << "后序递归遍历二叉树" << endl;
	PostOrder(tree);
	cout << endl;

    return 0;
}
