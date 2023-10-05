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
{//���Ѵ��ڸ���ֵ,�򷵻�0
	if (this->root==NULL)
	{
		
		this->root = new binarySearchNode<T>(date);
		return 1;
	}

	binarySearchNode<T>* node = new binarySearchNode<T>(date);// ��Ҫ����Ľڵ�
	binarySearchNode<T>* curPos = this->root;
	while (!curPos->isLeaf())
	{
		if (node->key < curPos->key)
		{//����
			if (curPos->leftChild!=NULL)
			{//�����ƶ�
				curPos = curPos->leftChild;
			}
			else
			{//�����ƶ���������Ϊ��
				curPos->leftChild = node;
				return 1;
			}
			
		}
		else if (node->key > curPos->key)
		{//����
			if (curPos->rightChild!=NULL)
			{//�����ƶ�
				curPos = curPos->rightChild;
			}
			else
			{//�����ƶ���������Ϊ��
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
	//��ʱ������δ���������ָ�뵱ǰλ��Ҷ�ڵ�,��ֵ�����ֿ���

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
	//int key= dateToKey(date);// ��Ҫ�����Ľڵ�
	binarySearchNode<T>* curPos = this->root;//ָ��

	if (this->root == NULL){return 0;}
	if (this->root->key==key)
	{//���ڵ㼴Ϊ����Ŀ��
		return 1;
	}

	
	
	while (!curPos->isLeaf())
	{
		if (key < curPos->key)
		{//����
			if (curPos->leftChild != NULL)
			{//�����ƶ�
				curPos = curPos->leftChild;
			}
			else
			{//�����ƶ���������Ϊ��,˵��������
				
				return 0;
			}

		}
		else if (key > curPos->key)
		{//����
			if (curPos->rightChild != NULL)
			{//�����ƶ�
				curPos = curPos->rightChild;
			}
			else
			{//�����ƶ���������Ϊ��,˵��������
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
	//��ʱ������δ���������ָ�뵱ǰλ��Ҷ�ڵ�,��ֵ�����ֿ���

	if (key == curPos->key)
	{//��ȿ���
		return 1;
	}
	return 0;//����ȿ���
}


template<typename T>
bool binarySearchTree<T>::deleteNode(binarySearchNode<T>* parentOfNodeToDelete, char LorR)
{
	binarySearchNode<T>* curPos = NULL;
	binarySearchNode<T>* nodeToDelete=NULL;
	
	if (LorR=='L')
	{//�˴������˿��ܵĶ�������
		
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
	{//ɾ�����Ƕ������������ڵ�



	}
	else
	{
		return 0;
	}

	
	if (curPos->leftChild!=NULL&& curPos->rightChild != NULL)
	{//�ڵ��Ϊ2,�ҵ����������ֵ��������Сֵ

		
		curPos = curPos->leftChild;
		binarySearchNode<T>* parentOfCur = curPos;//�˴�һ��
		while (curPos->rightChild!=NULL)
		{
			if (parentOfCur != curPos)
			{//ʹ������������һ��
				parentOfCur = parentOfCur->rightChild;
			}
			curPos = curPos->rightChild;
			
		}

		//��ʱָ��ָ��Ҷ�ڵ���Ϊһ�ڵ�
		if (curPos->isLeaf())
		{
			parentOfCur->rightChild = NULL;
			//to do, cur�滻delete node
			curPos->leftChild = nodeToDelete->leftChild;
			curPos->rightChild = nodeToDelete->rightChild;
			(LorR == 'L') ? parentOfNodeToDelete->leftChild=curPos: parentOfNodeToDelete->rightChild = curPos;
		}
		else
		{
			parentOfCur->rightChild = curPos->leftChild;
			//to do, cur�滻delete node
			curPos->leftChild = nodeToDelete->leftChild;
			curPos->rightChild = nodeToDelete->rightChild;
			(LorR == 'L') ? parentOfNodeToDelete->leftChild = curPos : parentOfNodeToDelete->rightChild = curPos;
		}


	}
	else if (curPos->leftChild != NULL)//ʡ�Բ�������
	{//ֻ�����������

		(LorR == 'L') ? 
			parentOfNodeToDelete->leftChild = curPos->leftChild : 
			parentOfNodeToDelete->rightChild = curPos->leftChild;

			delete curPos;

	}
	else if (curPos->rightChild != NULL)
	{//ֻ�����������
		(LorR == 'L') ?
			parentOfNodeToDelete->leftChild = curPos->rightChild :
			parentOfNodeToDelete->rightChild = curPos->rightChild;

		delete curPos;

	}








}

template<typename T>
bool binarySearchTree<T>::deleteNode(int key)
{

    //int key = dateToKey(date);// ��Ҫ�����Ľڵ�
	binarySearchNode<T>* curPos = this->root;//ָ��

	if (this->root == NULL) { return 0; }
	if (this->root->key == key)
	{//���ڵ㼴Ϊɾ��Ŀ��
		binarySearchNode<T>falseParentOfRoot;
		falseParentOfRoot.rightChild = this->root;
		deleteNode(&falseParentOfRoot, 'R');
		this->root = falseParentOfRoot.rightChild;

		return 1;
	}



	while (!curPos->isLeaf())
	{
		if (key < curPos->key)
		{//����
			if (curPos->leftChild != NULL)
			{//�����ƶ�
				if (curPos->leftChild->key == key)
				{
					deleteNode(curPos, 'L');//���� Ҫɾ���ڵ��ǰ�̽ڵ�  ��  ɾ���ڵ����丸�ڵ�Ĺ�ϵ
					return 1;
				}
				else
				{
					curPos = curPos->leftChild;
				}
				
			}
			else
			{//�����ƶ���������Ϊ��,˵��������

				return 0;
			}

		}
		else if (key > curPos->key)
		{//����
			if (curPos->rightChild != NULL)
			{//�����ƶ�
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
			{//�����ƶ���������Ϊ��,˵��������
				return 0;
			}

		}
		else
		{
			throw runtime_error("unknown");
		}


	}
	//��ʱ������δ���������ָ�뵱ǰλ��Ҷ�ڵ�,��ֵ�����ֿ���


	return 0;//�����ڸýڵ�
	
}

template<typename T>
void binarySearchTree<T>::preOrder(binarySearchNode<T>* root)
{
	if (root == NULL) { return; }
	//end����


	linkStack<binarySearchNode<T>*> tempStack;
	binarySearchNode<T>* curPos = root;
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
void binarySearchTree<T>::inOrder(binarySearchNode<T>* root)
{
	if (root == NULL) { return; }
	linkStack<binarySearchNode<T>*> tempStack;
	binarySearchNode<T>* curPos = root;

	binarySearchNode<T>falseRoot;
	falseRoot.rightChild = root;
	tempStack.push(&falseRoot);


	//����ջ
	while (!tempStack.isEmpty())
	{
		curPos = tempStack.getTop();
		tempStack.pop();
		if (curPos->rightChild != root)
		{//�����α���ڵ�
			cout << curPos->getDate() << ' ';
		}

		//end���ʵ�ǰ�ڵ�


		//begin����������
		if (curPos->rightChild != NULL)
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