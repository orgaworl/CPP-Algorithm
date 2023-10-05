#pragma once
#include"iostream"
#include"linkStack.hpp"
#include"linkQueue.hpp"
using namespace std;
//链表实现
//根节点位于第0层,序号为0




template<typename T>
class binaryTreeNode
{
	//friend class binaryTree<T>;
private:
	//binaryTreeNode* father;
	
	T date;

public:
	binaryTreeNode* leftChild;
	binaryTreeNode* rightChild;

	binaryTreeNode();
	binaryTreeNode(const T& date);
	binaryTreeNode(const T& date,binaryTreeNode*left,binaryTreeNode*right);
	~binaryTreeNode();
	T &getDate();                                          //返回当前树节点数据部分的 引用
	void setLeftChild(binaryTreeNode* left);
	void setRightChild(binaryTreeNode* right);
	void setCurDate(T&date);                                //引用 传入数据做当前节点数据
	bool isLeaf();
	bool isDegreeOne();

	bool operator< (binaryTreeNode other) { return this->getDate() < other.getDate(); };
	bool operator> (binaryTreeNode other) { return this->getDate() > other.getDate(); };
	



};

template<typename T>
class binaryTree
{
private:
	binaryTreeNode<T>* root;
public:
	//该树自身方法
	binaryTree();
	//binaryTree(binaryTree<T>*root);
	~binaryTree();
	bool isEmpty();
	binaryTreeNode<T>* getRoot();
	
	//begin该数作为树概念的方法
	binaryTreeNode<T>* getParent(binaryTreeNode<T>*curNode);
	binaryTreeNode<T>* getLeftSibling(binaryTreeNode<T>* curNode);
	binaryTreeNode<T>* getRightSibling(binaryTreeNode<T>* curNode);
	void creatNewTree(const T date,binaryTreeNode<T>*left,binaryTreeNode<T>*right);
	void creatNewTree(binaryTreeNode<T>* root);
	   
	void preOrderRecursion(binaryTreeNode<T>* root);
	void inOrderRecursion(binaryTreeNode<T>* root);
	void postOrderRecursion(binaryTreeNode<T>* root);
	void widthOrderRecursion(binaryTreeNode<T>* root);

	void preOrder(binaryTreeNode<T>*root);
	void inOrder(binaryTreeNode<T>* root);
	void postOrder(binaryTreeNode<T>* root);
	void widthOrder(binaryTreeNode<T>* root);

	int getTreeDepthR(binaryTreeNode<T>* root);
	int getTreeDepthNR(binaryTreeNode<T>* root);
	int countDegree1R(binaryTreeNode<T>* root);
	int countDegree1NR(binaryTreeNode<T>* root);
	
	void deleteBinaryTree(binaryTreeNode<T>* root);//将传入节点的所有子节点遍历delete
	//end

	



	
};

template<typename T>
binaryTreeNode<T>::binaryTreeNode()
{
	//date = T temp;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

template<typename T>
binaryTreeNode<T>::binaryTreeNode(const T& date)
{
	this->date = date;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

template<typename T>
binaryTreeNode<T>::binaryTreeNode(const T& date, binaryTreeNode* left, binaryTreeNode* right)
{
	this->date = date;
	this->leftChild = left;
	this->rightChild = right;
}

template<typename T>
binaryTreeNode<T>::~binaryTreeNode()
{
	
	delete this->leftChild;
	delete this->rightChild;

	
}

template<typename T>
T &binaryTreeNode<T>::getDate() 
{
	return this->date;
}

template<typename T>
void binaryTreeNode<T>::setLeftChild(binaryTreeNode* left)
{
	if (this->leftChild == NULL)
	{
		this->leftChild = left;
		return;
	}	
	else
	{
		cout << " E func setLeftChikd " << endl;
		return;
	}
	
}
template<typename T>
void binaryTreeNode<T>::setRightChild(binaryTreeNode* right)
{
	if (this->rightChild == NULL)
	{
		this->rightChild = right;
		return;
	}
	else
	{
		cout << " E func setRightChikd " << endl;
		return;
	}

	
}
template<typename T>
void binaryTreeNode<T>::setCurDate(T& date)
{
	this->date = date;
}
template<typename T>
bool binaryTreeNode<T>::isLeaf()
{
	if (this->leftChild==NULL&&rightChild==NULL)
	{
		return 1;
	}
	return 0;
}

template<typename T>
bool binaryTreeNode<T>::isDegreeOne()
{
	if ((this->leftChild == NULL && this->rightChild != NULL) || (this->leftChild != NULL  && this->rightChild == NULL))
	{
		return 1;
	}
	return 0;
}



template<typename T>
binaryTree<T>::binaryTree()
{
	root =NULL;
}
template<typename T>
binaryTree<T>::~binaryTree()
{

	//to finish
	delete root;
}
template<typename T>
bool binaryTree<T>::isEmpty()
{
	if (root->leftChild==NULL&&root->rightChild==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


template<typename T>
binaryTreeNode<T>* binaryTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
binaryTreeNode<T>* binaryTree<T>::getParent(binaryTreeNode<T>* curNode)
{

}
template<typename T>
binaryTreeNode<T>* binaryTree<T>::getLeftSibling(binaryTreeNode<T>* curNode)
{

}
template<typename T>
binaryTreeNode<T>* binaryTree<T>::getRightSibling(binaryTreeNode<T>* curNode)
{

}

template<typename T>
void binaryTree<T>::creatNewTree(const T date, binaryTreeNode<T>* left, binaryTreeNode<T>* right)
{
	root = new binaryTreeNode<T>(date);
	
	this->root->leftChild = left;
	this->root->rightChild = right;

}

template<typename T>
void binaryTree<T>::creatNewTree(binaryTreeNode<T>* root)
{
	this->root = root;
}

template<typename T>
void binaryTree<T>::deleteBinaryTree(binaryTreeNode<T>* root)
{
	//由深度优先遍历改来
		//广度优先遍历与深度优先遍历有区别,广度优先不需要再次调用此函数
	if (root == NULL) { return; }
	linkQueue<binaryTreeNode<T>*> tempQueue;
	binaryTree<T> conceptTree;
	binaryTreeNode<T>* curPos = root;


	
	if (curPos->leftChild != NULL)
	{
		tempQueue.enQueue(curPos->leftChild);
	}
	if (curPos->rightChild != NULL)
	{
		tempQueue.enQueue(curPos->rightChild);
	}
	delete root;


	while (!tempQueue.isEmpty())
	{
		//队列出队处节点数据访问并让其子节点进入队列,直至队列为空
		tempQueue.getFront(curPos);//队首数据传给curPos,并出队列
		tempQueue.deQueue();

		if (curPos->leftChild != NULL)
		{
			tempQueue.enQueue(curPos->leftChild);
		}
		if (curPos->rightChild != NULL)
		{
			tempQueue.enQueue(curPos->rightChild);
		}
		delete curPos;



	}


	tempQueue.clear();
	

}

template<typename T>
void binaryTree<T>::preOrderRecursion(binaryTreeNode<T>* root)
{
	if (root == NULL){return;}
	binaryTree<T> conceptTree;
	binaryTreeNode<T>* curPos = root;
	cout << curPos->getDate()<<' ';
	if (curPos->leftChild!=NULL)
	{
		preOrderRecursion(curPos->leftChild);
	}
	if (curPos->rightChild != NULL)
	{
		preOrderRecursion(curPos->rightChild);
	}
}

template<typename T>
void binaryTree<T>::inOrderRecursion(binaryTreeNode<T>* root)
{
	if (root == NULL){return;}
	binaryTree<T> conceptTree;
	binaryTreeNode<T>* curPos = root;
	if (curPos->leftChild != NULL)
	{
		inOrderRecursion(curPos->leftChild);
	}
	cout << curPos->getDate() << ' ';
	if (curPos->rightChild != NULL)
	{
		inOrderRecursion(curPos->rightChild);
	}
}


template<typename T>
void binaryTree<T>::postOrderRecursion(binaryTreeNode<T>* root)
{
	if (root == NULL){return;}
	binaryTree<T> conceptTree;
	binaryTreeNode<T>* curPos = root;

	if (curPos->leftChild != NULL)
	{
		postOrderRecursion(curPos->leftChild);
	}
	if (curPos->rightChild != NULL)
	{
		postOrderRecursion(curPos->rightChild);
	}
	cout << curPos->getDate() << ' ';

}

template<typename T>
int binaryTree<T>::getTreeDepthR(binaryTreeNode<T>* root)
{
	if (root == NULL){return -1;}

	int depth = -1;
	binaryTreeNode<T>* curPos = root;
	if (curPos->isLeaf())
	{
		return 0;
	}
	int leftDepth = getTreeDepthR(curPos->leftChild);
	int rightDepth = getTreeDepthR(curPos->rightChild);
	depth = (leftDepth >= rightDepth)?leftDepth+1 : rightDepth+1;
	return depth;
}

template<typename T>
int binaryTree<T>::getTreeDepthNR(binaryTreeNode<T>* root)
{//因为广度优先遍历使用的队列类为类模板而非特定的类,因此思路与参考答案有所不同

	if (root == NULL){return -1;}
	binaryTreeNode<T>* curPos = root;
	if (curPos->isLeaf()){return 0;}
	int depth = -1;
	linkQueue<binaryTreeNode<T>*> tempQueue;
	tempQueue.enQueue(curPos);
	tempQueue.enQueue(NULL);
	while (!tempQueue.isEmpty())
	{
		//队列出队处节点数据访问并让其子节点进入队列,直至队列为空
		tempQueue.deQueue(curPos);//队首数据传给curPos,并出队列
		if (curPos==NULL)
		{
			depth++;
			if (tempQueue.getFront() == NULL)
			{
				break;
			}
			continue;

		}
		if (curPos->leftChild != NULL)
		{
			tempQueue.enQueue(curPos->leftChild);
		}
		if (curPos->rightChild != NULL)
		{
			tempQueue.enQueue(curPos->rightChild);
		}
		if (tempQueue.getFront()==NULL)
		{
			tempQueue.enQueue(NULL);// 每层所有节点存入队列后,一个nullptr入队列做分割
		}
	

	}
	return depth;
	cout << endl;
	tempQueue.clear();


}

template<typename T>
int binaryTree<T>::countDegree1R(binaryTreeNode<T>* root)
{
	int num = 0;
	binaryTreeNode<T>* curPos = root;//创建指针指向计数的树的根节点
	if (curPos==NULL|| curPos->isLeaf()){return 0;}//空树或叶
	if ((curPos->leftChild == NULL && curPos->rightChild != NULL && curPos->rightChild->isLeaf()) || (curPos->leftChild != NULL && curPos->leftChild->isLeaf() && curPos->rightChild == NULL))
	{//节点度为1且其后继节点度为0时
		return 1;
	}
	num = countDegree1R(curPos->leftChild) +countDegree1R(curPos->rightChild);
	return num;
}

template<typename T>
int binaryTree<T>::countDegree1NR(binaryTreeNode<T>* root)
{
	int num = 0;
	binaryTreeNode<T>* curPos = root;
	if (curPos == NULL || curPos->isLeaf()) { return 0; }//空树或叶
	if ((curPos->leftChild == NULL && curPos->rightChild != NULL && curPos->rightChild->isLeaf()) || (curPos->leftChild != NULL && curPos->leftChild->isLeaf() && curPos->rightChild == NULL))
	{//当前节点度为1且其后继节点为叶 时
		return 1;
	}



	//begin递归转换为非递归 前序遍历
	linkStack<binaryTreeNode<T>*> tempStack;
	tempStack.push(curPos);

	
	while (!tempStack.isEmpty())
	{
		curPos = tempStack.getTop();
		tempStack.pop();
		if (curPos->isDegreeOne())
		{
			num++;
		}
	

		while (!curPos->isLeaf())
		{
			if (curPos->rightChild != NULL)
			{
				tempStack.push(curPos->rightChild);
			}
			if (curPos->leftChild != NULL)
			{
				curPos = curPos->leftChild;
				if (curPos->isDegreeOne())
				{
					num++;
				}
			}
			else
			{
				break;
			}
		}

	}


	cout << '\n';
	tempStack.clear();
	return num;
}


template<typename T>
void binaryTree<T>::preOrder(binaryTreeNode<T>* root)
{
	if (root == NULL){return;}
	//end过滤


	linkStack<binaryTreeNode<T>*> tempStack;
	binaryTreeNode<T>* curPos=root;
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
void binaryTree<T>::inOrder(binaryTreeNode<T>* root)
{
	
	if (root==NULL){return;}
	linkStack<binaryTreeNode<T>*> tempStack;
	binaryTreeNode<T>* curPos = root;

	binaryTreeNode<T> falseRoot;
	falseRoot.rightChild = root;
	tempStack.push(&falseRoot);
	

	//处理栈
	while (!tempStack.isEmpty())
	{
		
		curPos = tempStack.getTop();
		tempStack.pop();
		if (curPos->rightChild!=root)
		{//不输出伪根节点
			cout << curPos->getDate() << ' ';
		}
		
		//end访问当前节点
		

		//begin访问右子树
		if (curPos->rightChild!=NULL)
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
class stackElement
{
public:
	T p;
	char tag;
	stackElement()
	{
		p = NULL;
		tag = NULL;
	}
	stackElement(T p, char tag)
	{

		this->p = p;
		this->tag = tag;
	}
	
};

template<typename T>
void binaryTree<T>::postOrder(binaryTreeNode<T>* root)
{

	//每个stack element中包含一个节点和一个字符(L表示正在进行该节点左树,R表示正在进行该节点右树)
	//对于每个节点,先将该节点存入栈中,并标为L,后进入其左子树.如此循环直至到达叶节点

	if (root == NULL){return;}
	linkStack<stackElement<binaryTreeNode<T>*>> tempStack;
	binaryTreeNode<T>* curPos = root;

	//begin遍历到头
	while (curPos->leftChild!=NULL)
	{
		stackElement<binaryTreeNode<T>*> element(curPos, 'L');
		tempStack.push(element);
		curPos = curPos->leftChild;

	}
	if (curPos->rightChild==NULL)
	{//终末为叶节点
		cout << curPos->getDate() << ' ';
	}
	else
	{//终末左子树为空,存在右子树
		stackElement<binaryTreeNode<T>*> element(curPos, 'L');
		tempStack.push(element);
	}
	//end



	//begin处理栈内部分
	while (!tempStack.isEmpty())
	{
		
		if (tempStack.getTop().tag == 'L')
		{//若当前节点左树遍历过,即将遍历右树
			

			tempStack.getTop().tag = 'R';
			
			curPos = tempStack.getTop().p;//1
			if (curPos->rightChild != NULL)
			{
				curPos = curPos->rightChild;
				//conceptTree.postOrder(tempStack.getTop().p->rightChild);此句递归可写成以下:
				//begin遍历到头
				while (curPos->leftChild != NULL)
				{
					stackElement<binaryTreeNode<T>*> element(curPos, 'L');
					tempStack.push(element);
					curPos = curPos->leftChild;

				}
				if (curPos->rightChild == NULL)
				{//终末为叶节点
					cout << curPos->getDate() << ' ';
				}
				else
				{//终末左子树为空,存在右子树
					stackElement<binaryTreeNode<T>*> element(curPos, 'L');
					tempStack.push(element);
				}
				//end









			}

		}
		else if (tempStack.getTop().tag=='R')
		{//若当前节点左右树都遍历过

			cout<<tempStack.getTop().p->getDate() << ' ';
			tempStack.pop();
		}
		
	}
	//end
	cout << endl;
	tempStack.clear();

}

template<typename T>
void binaryTree<T>::widthOrder(binaryTreeNode<T>* root)
{

	//广度优先遍历与深度优先遍历有区别,广度优先不需要再次调用此函数
	
	if (root == NULL) { return; }
	linkQueue<binaryTreeNode<T>*> tempQueue;
	binaryTreeNode<T>* curPos = root;

	
		cout << curPos->getDate() << ' ';
		if (curPos->leftChild != NULL)
		{
			tempQueue.enQueue(curPos->leftChild);
		}
		if (curPos->rightChild != NULL)
		{
			tempQueue.enQueue(curPos->rightChild);
		}

		
		while (!tempQueue.isEmpty())
		{
			//队列出队处节点数据访问并让其子节点进入队列,直至队列为空
			//tempQueue.getFront();//队首数据传给curPos,并出队列
			tempQueue.deQueue(curPos);
			cout << curPos->getDate() << ' ';

			if (curPos->leftChild != NULL)
			{
				tempQueue.enQueue(curPos->leftChild);
			}
			if (curPos->rightChild != NULL)
			{
				tempQueue.enQueue(curPos->rightChild);
			}




		}

		
		tempQueue.clear();

}
void func_ti()
{

}