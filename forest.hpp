#pragma once
#include<iostream>
using namespace std;
template<typename T>
class forestNode
{
public:

	T date;

public:
	forestNode* leftChild;
	forestNode* rightSibling;

	forestNode();
	forestNode(const T& date);
	forestNode(const T& date, forestNode<T>* left, forestNode<T>* right);
	~forestNode();
	T& getDate();                                          //返回当前树节点数据部分的 引用
	void setLeftChild(forestNode<T>* left);
	void setRightSibling(forestNode<T>* right);
	void setCurDate(T& date);                                //引用 传入数据做当前节点数据
	bool isLeaf();
	




};

template<typename T>
class forest
{
private:
	forestNode<T>* root;
public:
	//该树自身方法
	forest();
	~forest();
	bool isTree();
	forestNode<T>*& getRoot();
	int CreateForest(forestNode<T>*& root);
	//begin该数作为树概念的方法

	void preRootOrderRecursion(forestNode<T>* root);
	void postRootOrderRecursion(forestNode<T>* root);
	void widthOrderRecursion(forestNode<T>* root);

	void preOrder(forestNode<T>* root);
	void inOrder(forestNode<T>* root);
	void widthOrder(forestNode<T>* root);



	int getTreeDepthR(forestNode<T>* root);
	int getTreeDepthNR(forestNode<T>* root);

	int countDegree1R(forestNode<T>* root);
	int countDegree1NR(forestNode<T>* root);

	int countLeafR(forestNode<T>*root);
	int countHeightR(forestNode<T>* root);
};


template<typename T>
int forest<T>::CreateForest(forestNode<T>*&root)
{
	
	T ch;
	T temp;
	

	cin >> ch;
	temp = cin.get();
	if (ch == -1)
	{
		root = NULL;
	}
	else {
		
		root = new forestNode<T>(ch);
		cout << "请输入" << ch << "的子树";
		CreateForest(root->leftChild);
		cout << "请输入" << ch << "的兄弟";
		CreateForest(root->rightSibling);
	}
	return 1;
}


//类与方法分割线*******************************************************************************
template<typename T>
forestNode<T>::forestNode()
{
	//date = T temp;
	this->leftChild = NULL;
	this->rightSibling = NULL;
}

template<typename T>
forestNode<T>::forestNode(const T& date)
{
	this->date = date;
	this->leftChild = NULL;
	this->rightSibling = NULL;
}

template<typename T>
forestNode<T>::forestNode(const T& date, forestNode* left, forestNode* right)
{
	this->date = date;
	this->leftChild = left;
	this->rightSibling = right;
}

template<typename T>
forestNode<T>::~forestNode()
{

	delete this->leftChild;
	delete this->rightSibling;


}

template<typename T>
T& forestNode<T>::getDate()
{
	return this->date;
}

template<typename T>
void forestNode<T>::setLeftChild(forestNode<T>* left)
{
		this->leftChild = left;
}
template<typename T>
void forestNode<T>::setRightSibling(forestNode<T>* right)
{
	if (this->rightSibling == NULL)
	{
		this->rightSibling = right;
		return;
	}
	else
	{
		cout << " E func setRightChikd " << endl;
		return;
	}


}
template<typename T>
void forestNode<T>::setCurDate(T& date)
{
	this->date = date;
}
template<typename T>
bool forestNode<T>::isLeaf()
{
	if (this->leftChild == NULL && this->leftChild->rightSibling == NULL)
	{
		return 1;
	}
	return 0;
}

template<typename T>
forestNode<T>*& forest<T>::getRoot()
{
	return this->root;
}





//****************************************************************************************************


template<typename T>
forest<T>::forest()
{
	root = NULL;
}
template<typename T>
forest<T>::~forest()
{

	//to finish
	delete root;
}

template<typename T>
bool forest<T>::isTree()
{
	return root != NULL && root->rightSibling == NULL;

}


template<typename T>
void forest<T>::preRootOrderRecursion(forestNode<T>* root)
{
	if (root == NULL) { return; }
	forestNode<T>* curPos = root;
	cout << curPos->getDate() << ' ';
	if (curPos->leftChild != NULL)
	{
		preRootOrderRecursion(curPos->leftChild);
	}
	if (curPos->rightSibling != NULL)
	{
		preRootOrderRecursion(curPos->rightSibling);
	}
}

template<typename T>
void forest<T>::postRootOrderRecursion(forestNode<T>* root)
{
	if (root == NULL) { return; }
	forestNode<T>* curPos = root;
	if (curPos->leftChild != NULL)
	{
		postRootOrderRecursion(curPos->leftChild);
	}
	cout << curPos->getDate() << ' ';
	if (curPos->rightSibling != NULL)
	{
		postRootOrderRecursion(curPos->rightSibling);
	}
}




template<typename T>
int  forest<T>::countLeafR(forestNode<T>* root)
{
	if (root==NULL)
	{
		return 0;
	}
	forestNode<T>* curPoi = root;
	int sum= 0;
	//没有左的就是叶节点

	if (root->rightSibling != NULL)
	{
		
		while (curPoi->rightSibling!= NULL)
		{
			sum += curPoi->leftChild != NULL ? countLeafR(curPoi->leftChild) : 1;
			curPoi = curPoi->rightSibling;

		}
		sum += curPoi->leftChild != NULL ? countLeafR(curPoi->leftChild) : 1;
	}
	else
	{

		sum = curPoi->leftChild != NULL ? countLeafR(curPoi->leftChild): 1;
	}


	return sum;
}

template<typename T>
int  forest<T>::countHeightR(forestNode<T>* root)
{
	if (root==NULL)
	{
		return 0;
	}
	forestNode<T>*curPoi = root;
	int max=0, subMax1=0, subMax2 = 0;

	if (root->rightSibling != NULL)
	{
		int temp = 0;
		subMax1 = curPoi->leftChild!=NULL?countHeightR(curPoi->leftChild)+1:1;
		subMax2 = curPoi->rightSibling->leftChild != NULL ? countHeightR(curPoi->rightSibling->leftChild) + 1:1;
		while (curPoi->rightSibling->rightSibling != NULL)
		{
			temp = subMax1 > subMax2 ? subMax1 : subMax2;
			if (temp>max)
			{
				max = temp;
			}
			subMax1 = subMax2;
			curPoi = curPoi->rightSibling;
			subMax2 = curPoi->rightSibling->leftChild != NULL ? countHeightR(curPoi->rightSibling->leftChild) + 1 : 1;

		}
		temp = subMax1 > subMax2 ? subMax1 : subMax2;
		if (temp > max)
		{
			max = temp;
		}
	}
	else
	{
		max = curPoi->leftChild != NULL ? countHeightR(curPoi->leftChild) + 1 : 1;

	}
	
	
	return max;

}



