#pragma once
#include"iostream"
#include"linkStack.hpp"
#include"linkQueue.hpp"
using namespace std;

template<typename T>
int dateToKey(T date)
{
	//ennnnnnnnnnn  MD5?
	int key_ = (int)(date);
	return key_;
}

template<typename T>
class binarySearchNode
{
private:
	T date;
public:
	int key;
	binarySearchNode<T>* leftChild;
	binarySearchNode<T>* rightChild;
	//int dateToKey(T);
	binarySearchNode();
	binarySearchNode(T);
	bool isLeaf();
	T& getDate();
	
};


template<typename T>
binarySearchNode<T>::binarySearchNode()
{
	this->key = -1;
	//date=
	this->leftChild = NULL;
	this->rightChild = NULL;

}

template<typename T>
binarySearchNode<T>::binarySearchNode(T date)
{
	key = dateToKey(date);
	this->getDate() = date;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

template<typename T>
bool binarySearchNode<T>::isLeaf()
{
	if (this->leftChild == NULL && rightChild == NULL)
	{
		return 1;
	}
	return 0;
}

template<typename T>
T& binarySearchNode<T>::getDate()
{
	return this->date;
}











template<typename T>
class binarySearchTree
{
private:
	binarySearchNode<T>* root;

public:
	binarySearchTree();
	bool insertNode(T date);
	bool serachNode(int key);
	bool deleteNode(int key);
	bool deleteNode(binarySearchNode<T>*parentOfNodeToDelete,char LorR);
	void preOrder(binarySearchNode<T>* root);
	void inOrder(binarySearchNode<T>* root);
	binarySearchNode<T>* getRoot();
};
template<typename T>
binarySearchTree<T>::binarySearchTree()
{
	root = NULL;

}


template<typename T>
bool binarySearchTree<T>::insertNode(T date)
{//若已存在该数值,则返回0
	if (this->root==NULL)
	{
		
		this->root = new binarySearchNode<T>(date);
		return 1;
	}

	binarySearchNode<T>* node = new binarySearchNode<T>(date);// 将要插入的节点
	binarySearchNode<T>* curPos = this->root;
	while (!curPos->isLeaf())
	{
		if (node->key < curPos->key)
		{//向左
			if (curPos->leftChild!=NULL)
			{//向左移动
				curPos = curPos->leftChild;
			}
			else
			{//向左移动但左子树为空
				curPos->leftChild = node;
				return 1;
			}
			
		}
		else if (node->key > curPos->key)
		{//向右
			if (curPos->rightChild!=NULL)
			{//向右移动
				curPos = curPos->rightChild;
			}
			else
			{//向右移动但柚子树为空
				curPos->rightChild = node;
				return 1;
			}
			
		}
		else if (node->key == curPos->key)
		{
			return 0;
		}
		else
		{
			throw runtime_error("unknown");
		}


	}
	//此时程序尚未结束则表明指针当前位于叶节点,数值有三种可能

	if (node->key == curPos->key)
	{
		return 0;
	}
	else if(node->key < curPos->key)
	{
		curPos->leftChild = node;
	}
	else if (node->key > curPos->key)
	{
		curPos->rightChild = node;
	}
	return 1;

}


template<typename T>
bool binarySearchTree<T>::serachNode(int key)
{
	//int key= dateToKey(date);// 将要检索的节点
	binarySearchNode<T>* curPos = this->root;//指针

	if (this->root == NULL){return 0;}
	if (this->root->key==key)
	{//根节点即为查找目标
		return 1;
	}

	
	
	while (!curPos->isLeaf())
	{
		if (key < curPos->key)
		{//向左
			if (curPos->leftChild != NULL)
			{//向左移动
				curPos = curPos->leftChild;
			}
			else
			{//向左移动但左子树为空,说明不存在
				
				return 0;
			}

		}
		else if (key > curPos->key)
		{//向右
			if (curPos->rightChild != NULL)
			{//向右移动
				curPos = curPos->rightChild;
			}
			else
			{//向右移动但柚子树为空,说明不存在
				return 0;
			}

		}
		else if (key == curPos->key)
		{
			return 1;
		}
		else
		{
			throw runtime_error("unknown");
		}


	}
	//此时程序尚未结束则表明指针当前位于叶节点,数值有三种可能

	if (key == curPos->key)
	{//相等可能
		return 1;
	}
	return 0;//不相等可能
}


template<typename T>
bool binarySearchTree<T>::deleteNode(binarySearchNode<T>* parentOfNodeToDelete, char LorR)
{
	binarySearchNode<T>* curPos = NULL;
	binarySearchNode<T>* nodeToDelete=NULL;
	
	if (LorR=='L')
	{//此处忽略了可能的恶意输入
		
		if ((curPos = nodeToDelete = parentOfNodeToDelete->leftChild)->isLeaf())
		{
			delete curPos;
			parentOfNodeToDelete->leftChild = NULL;
			return 1;
		}
	}
	else if (LorR == 'R')
	{
		if ((curPos = nodeToDelete = parentOfNodeToDelete->rightChild)->isLeaf())
		{
			delete curPos;
			parentOfNodeToDelete->rightChild = NULL;
			return 1;
		}
		
	}
	else if (LorR == 'C')
	{//删除的是二叉搜索树根节点



	}
	else
	{
		return 0;
	}

	
	if (curPos->leftChild!=NULL&& curPos->rightChild != NULL)
	{//节点度为2,找到左子树最大值或右子树小值

		
		curPos = curPos->leftChild;
		binarySearchNode<T>* parentOfCur = curPos;//此处一致
		while (curPos->rightChild!=NULL)
		{
			if (parentOfCur != curPos)
			{//使父比子少右移一次
				parentOfCur = parentOfCur->rightChild;
			}
			curPos = curPos->rightChild;
			
		}

		//此时指针指向叶节点或度为一节点
		if (curPos->isLeaf())
		{
			parentOfCur->rightChild = NULL;
			//to do, cur替换delete node
			curPos->leftChild = nodeToDelete->leftChild;
			curPos->rightChild = nodeToDelete->rightChild;
			(LorR == 'L') ? parentOfNodeToDelete->leftChild=curPos: parentOfNodeToDelete->rightChild = curPos;
		}
		else
		{
			parentOfCur->rightChild = curPos->leftChild;
			//to do, cur替换delete node
			curPos->leftChild = nodeToDelete->leftChild;
			curPos->rightChild = nodeToDelete->rightChild;
			(LorR == 'L') ? parentOfNodeToDelete->leftChild = curPos : parentOfNodeToDelete->rightChild = curPos;
		}


	}
	else if (curPos->leftChild != NULL)//省略部分条件
	{//只有左子树情况

		(LorR == 'L') ? 
			parentOfNodeToDelete->leftChild = curPos->leftChild : 
			parentOfNodeToDelete->rightChild = curPos->leftChild;

			delete curPos;

	}
	else if (curPos->rightChild != NULL)
	{//只有右子树情况
		(LorR == 'L') ?
			parentOfNodeToDelete->leftChild = curPos->rightChild :
			parentOfNodeToDelete->rightChild = curPos->rightChild;

		delete curPos;

	}








}

template<typename T>
bool binarySearchTree<T>::deleteNode(int key)
{

    //int key = dateToKey(date);// 将要检索的节点
	binarySearchNode<T>* curPos = this->root;//指针

	if (this->root == NULL) { return 0; }
	if (this->root->key == key)
	{//根节点即为删除目标
		binarySearchNode<T>falseParentOfRoot;
		falseParentOfRoot.rightChild = this->root;
		deleteNode(&falseParentOfRoot, 'R');
		this->root = falseParentOfRoot.rightChild;

		return 1;
	}



	while (!curPos->isLeaf())
	{
		if (key < curPos->key)
		{//向左
			if (curPos->leftChild != NULL)
			{//向左移动
				if (curPos->leftChild->key == key)
				{
					deleteNode(curPos, 'L');//传入 要删除节点的前继节点  和  删除节点与其父节点的关系
					return 1;
				}
				else
				{
					curPos = curPos->leftChild;
				}
				
			}
			else
			{//向左移动但左子树为空,说明不存在

				return 0;
			}

		}
		else if (key > curPos->key)
		{//向右
			if (curPos->rightChild != NULL)
			{//向右移动
				if (curPos->rightChild->key==key)
				{
					deleteNode(curPos, 'R');
					return 1;
				}
				else
				{
					curPos = curPos->rightChild;
				}
				
			}
			else
			{//向右移动但柚子树为空,说明不存在
				return 0;
			}

		}
		else
		{
			throw runtime_error("unknown");
		}


	}
	//此时程序尚未结束则表明指针当前位于叶节点,数值有三种可能


	return 0;//不存在该节点
	
}

template<typename T>
void binarySearchTree<T>::preOrder(binarySearchNode<T>* root)
{
	if (root == NULL) { return; }
	//end过滤


	linkStack<binarySearchNode<T>*> tempStack;
	binarySearchNode<T>* curPos = root;
	tempStack.push(curPos);//将整个树等效为一个右子树存入栈


	//begin处理栈内部分
	while (!tempStack.isEmpty())
	{
		curPos = tempStack.getTop();
		tempStack.pop();

		//conceptTree.preOrder(curPos);此句递归,等效于以下语句
			//遍历到底,将未遍历部分存入栈内
		cout << curPos->getDate() << ' ';
		while (!curPos->isLeaf())
		{
			if (curPos->rightChild != NULL)
			{//右子树非空则存入栈内
				tempStack.push(curPos->rightChild);
			}
			if (curPos->leftChild != NULL)
			{//左子树非空则指针指向左子树
				curPos = curPos->leftChild;
				cout << curPos->getDate() << ' ';
			}
			else
			{//左子树为空,结束循环
				break;
			}
		}

	}

	cout << '\n';
	tempStack.clear();


}
template<typename T>
void binarySearchTree<T>::inOrder(binarySearchNode<T>* root)
{
	if (root == NULL) { return; }
	linkStack<binarySearchNode<T>*> tempStack;
	binarySearchNode<T>* curPos = root;

	binarySearchNode<T>falseRoot;
	falseRoot.rightChild = root;
	tempStack.push(&falseRoot);


	//处理栈
	while (!tempStack.isEmpty())
	{
		curPos = tempStack.getTop();
		tempStack.pop();
		if (curPos->rightChild != root)
		{//不输出伪根节点
			cout << curPos->getDate() << ' ';
		}

		//end访问当前节点


		//begin访问右子树
		if (curPos->rightChild != NULL)
		{
			curPos = curPos->rightChild;//2
			//inOrder(curPos); 此句递归等效于以下语句
			while (curPos->leftChild != NULL)
			{//当前节点非叶,则将当前节点存入栈
				tempStack.push(curPos);
				curPos = curPos->leftChild;

			}
			if (curPos->rightChild == NULL)
			{//终末为叶节点
				cout << curPos->getDate() << ' ';
			}
			else
			{//终末左子树为空,存在右子树
				tempStack.push(curPos);

			}


		}

	}
	cout << '\n';
	tempStack.clear();
}


template<typename T>
binarySearchNode<T>* binarySearchTree<T>::getRoot()
{
	return this->root;
}

void testBinaeySearchTree()
{
	srand((unsigned int)time(NULL));
	binarySearchTree<int> bst;

	/*for (int i=0;i<=9;i++)
	{
		int randNum = rand() % (10);
		cout<<randNum<<' '<<bst.insertNode(randNum) << endl;

	}*/

	bst.insertNode(5);
	bst.insertNode(3);
	bst.insertNode(1);
	bst.insertNode(2);
	bst.insertNode(4);
	bst.insertNode(10);
	bst.insertNode(-1);
	bst.insertNode(-3);
	bst.insertNode(-2);
	bst.insertNode(11);
	bst.insertNode(9);
	cout << endl << endl;
	cout << bst.deleteNode(5) << endl;
	bst.inOrder(bst.getRoot());
}