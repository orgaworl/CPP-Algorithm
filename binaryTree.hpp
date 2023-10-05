#pragma once
#include"iostream"
#include"linkStack.hpp"
#include"linkQueue.hpp"
using namespace std;
//����ʵ��
//���ڵ�λ�ڵ�0��,���Ϊ0




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
	T &getDate();                                          //���ص�ǰ���ڵ����ݲ��ֵ� ����
	void setLeftChild(binaryTreeNode* left);
	void setRightChild(binaryTreeNode* right);
	void setCurDate(T&date);                                //���� ������������ǰ�ڵ�����
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
	//����������
	binaryTree();
	//binaryTree(binaryTree<T>*root);
	~binaryTree();
	bool isEmpty();
	binaryTreeNode<T>* getRoot();
	
	//begin������Ϊ������ķ���
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
	
	void deleteBinaryTree(binaryTreeNode<T>* root);//������ڵ�������ӽڵ����delete
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
	//��������ȱ�������
		//������ȱ�����������ȱ���������,������Ȳ���Ҫ�ٴε��ô˺���
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
		//���г��Ӵ��ڵ����ݷ��ʲ������ӽڵ�������,ֱ������Ϊ��
		tempQueue.getFront(curPos);//�������ݴ���curPos,��������
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
{//��Ϊ������ȱ���ʹ�õĶ�����Ϊ��ģ������ض�����,���˼·��ο���������ͬ

	if (root == NULL){return -1;}
	binaryTreeNode<T>* curPos = root;
	if (curPos->isLeaf()){return 0;}
	int depth = -1;
	linkQueue<binaryTreeNode<T>*> tempQueue;
	tempQueue.enQueue(curPos);
	tempQueue.enQueue(NULL);
	while (!tempQueue.isEmpty())
	{
		//���г��Ӵ��ڵ����ݷ��ʲ������ӽڵ�������,ֱ������Ϊ��
		tempQueue.deQueue(curPos);//�������ݴ���curPos,��������
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
			tempQueue.enQueue(NULL);// ÿ�����нڵ������к�,һ��nullptr��������ָ�
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
	binaryTreeNode<T>* curPos = root;//����ָ��ָ����������ĸ��ڵ�
	if (curPos==NULL|| curPos->isLeaf()){return 0;}//������Ҷ
	if ((curPos->leftChild == NULL && curPos->rightChild != NULL && curPos->rightChild->isLeaf()) || (curPos->leftChild != NULL && curPos->leftChild->isLeaf() && curPos->rightChild == NULL))
	{//�ڵ��Ϊ1�����̽ڵ��Ϊ0ʱ
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
	if (curPos == NULL || curPos->isLeaf()) { return 0; }//������Ҷ
	if ((curPos->leftChild == NULL && curPos->rightChild != NULL && curPos->rightChild->isLeaf()) || (curPos->leftChild != NULL && curPos->leftChild->isLeaf() && curPos->rightChild == NULL))
	{//��ǰ�ڵ��Ϊ1�����̽ڵ�ΪҶ ʱ
		return 1;
	}



	//begin�ݹ�ת��Ϊ�ǵݹ� ǰ�����
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
	//end����


	linkStack<binaryTreeNode<T>*> tempStack;
	binaryTreeNode<T>* curPos=root;
	tempStack.push(curPos);//����������ЧΪһ������������ջ


	//begin����ջ�ڲ���
	while (!tempStack.isEmpty())
	{
		curPos = tempStack.getTop();
		tempStack.pop();

		//conceptTree.preOrder(curPos);�˾�ݹ�,��Ч���������
			//��������,��δ�������ִ���ջ��
		cout << curPos->getDate() << ' ';
		while (!curPos->isLeaf())
		{
			if (curPos->rightChild != NULL)
			{//�������ǿ������ջ��
				tempStack.push(curPos->rightChild);
			}
			if (curPos->leftChild != NULL)
			{//�������ǿ���ָ��ָ��������
				curPos = curPos->leftChild;
				cout << curPos->getDate() << ' ';
			}
			else
			{//������Ϊ��,����ѭ��
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
	

	//����ջ
	while (!tempStack.isEmpty())
	{
		
		curPos = tempStack.getTop();
		tempStack.pop();
		if (curPos->rightChild!=root)
		{//�����α���ڵ�
			cout << curPos->getDate() << ' ';
		}
		
		//end���ʵ�ǰ�ڵ�
		

		//begin����������
		if (curPos->rightChild!=NULL)
		{
			curPos = curPos->rightChild;//2
			//inOrder(curPos); �˾�ݹ��Ч���������
			while (curPos->leftChild != NULL)
			{//��ǰ�ڵ��Ҷ,�򽫵�ǰ�ڵ����ջ
				tempStack.push(curPos);
				curPos = curPos->leftChild;

			}
			if (curPos->rightChild == NULL)
			{//��ĩΪҶ�ڵ�
				cout << curPos->getDate() << ' ';
			}
			else
			{//��ĩ������Ϊ��,����������
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

	//ÿ��stack element�а���һ���ڵ��һ���ַ�(L��ʾ���ڽ��иýڵ�����,R��ʾ���ڽ��иýڵ�����)
	//����ÿ���ڵ�,�Ƚ��ýڵ����ջ��,����ΪL,�������������.���ѭ��ֱ������Ҷ�ڵ�

	if (root == NULL){return;}
	linkStack<stackElement<binaryTreeNode<T>*>> tempStack;
	binaryTreeNode<T>* curPos = root;

	//begin������ͷ
	while (curPos->leftChild!=NULL)
	{
		stackElement<binaryTreeNode<T>*> element(curPos, 'L');
		tempStack.push(element);
		curPos = curPos->leftChild;

	}
	if (curPos->rightChild==NULL)
	{//��ĩΪҶ�ڵ�
		cout << curPos->getDate() << ' ';
	}
	else
	{//��ĩ������Ϊ��,����������
		stackElement<binaryTreeNode<T>*> element(curPos, 'L');
		tempStack.push(element);
	}
	//end



	//begin����ջ�ڲ���
	while (!tempStack.isEmpty())
	{
		
		if (tempStack.getTop().tag == 'L')
		{//����ǰ�ڵ�����������,������������
			

			tempStack.getTop().tag = 'R';
			
			curPos = tempStack.getTop().p;//1
			if (curPos->rightChild != NULL)
			{
				curPos = curPos->rightChild;
				//conceptTree.postOrder(tempStack.getTop().p->rightChild);�˾�ݹ��д������:
				//begin������ͷ
				while (curPos->leftChild != NULL)
				{
					stackElement<binaryTreeNode<T>*> element(curPos, 'L');
					tempStack.push(element);
					curPos = curPos->leftChild;

				}
				if (curPos->rightChild == NULL)
				{//��ĩΪҶ�ڵ�
					cout << curPos->getDate() << ' ';
				}
				else
				{//��ĩ������Ϊ��,����������
					stackElement<binaryTreeNode<T>*> element(curPos, 'L');
					tempStack.push(element);
				}
				//end









			}

		}
		else if (tempStack.getTop().tag=='R')
		{//����ǰ�ڵ���������������

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

	//������ȱ�����������ȱ���������,������Ȳ���Ҫ�ٴε��ô˺���
	
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
			//���г��Ӵ��ڵ����ݷ��ʲ������ӽڵ�������,ֱ������Ϊ��
			//tempQueue.getFront();//�������ݴ���curPos,��������
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