#pragma once
#include"iostream"
using namespace std;


template<typename T>
class arrBinaryTree
{
private:
	T* list;
	int curSize = 0;
public:
	//����������
	arrBinaryTree();
	~arrBinaryTree();
	bool isEmpty();
	

	//begin������Ϊ������ķ���
	binaryTreeNode<T>* getParent(binaryTreeNode<T>* curNode);
	binaryTreeNode<T>* getLeftSibling(binaryTreeNode<T>* curNode);
	binaryTreeNode<T>* getRightSibling(binaryTreeNode<T>* curNode);
	void creatNewTree(const T date, binaryTreeNode<T>* left, binaryTreeNode<T>* right);
	void creatNewTree(binaryTreeNode<T>* root);


	void preOrder(binaryTreeNode<T>* root);
	void inOrder(binaryTreeNode<T>* root);
	void postOrder(binaryTreeNode<T>* root);
	void widthOrder(binaryTreeNode<T>* root);


	void deleteBinaryTree(binaryTreeNode<T>* root);//������ڵ�������ӽڵ����delete
	//end




};
template<typename T>
arrBinaryTree<T>::arrBinaryTree()
{

}
template<typename T>
arrBinaryTree<T>::~arrBinaryTree()
{

}
template<typename T>
bool arrBinaryTree<T>::isEmpty()
{

}