#include<iostream>
#include"binaryTree.hpp"
#include"Ex_6.h"
#include<cmath>






void testBinaryTree()
{
	//binaryTree<int>a;
	//creatTreeFullBinaryTree(a, 2);
	//a.preOrderRecursion(a.getRoot()); cout << '\n';
	//a.inOrderRecursion(a.getRoot());  cout << '\n';
	//a.postOrderRecursion(a.getRoot()); cout << '\n';
	//a.widthOrder(a.getRoot());        cout << '\n';//
	//cout << "�ݹ�ʵ�ּ������"<< a.getTreeDepthR(a.getRoot()) << '\n '
	// << "�ǵݹ�ʵ�ּ������"<< a.getTreeDepthNR(a.getRoot()) << ' ';
	//cout<< "�ݹ�ʵ�ּ����Ϊһ�ڵ����" << a.countDegree1R(a.getRoot())<< '\n' 
	//<< "�ǵݹ�ʵ�ּ������" << a.countDegree1NR(a.getRoot()) << '\n';


	//binaryTree<int>b;
	//creatOutBinaryTree(b, 2);
	//b.preOrderRecursion(b.getRoot()); cout << '\n';
	//b.inOrderRecursion(b.getRoot());  cout << '\n';
	//b.postOrderRecursion(b.getRoot()); cout << '\n';
	//b.widthOrder(b.getRoot());        cout << '\n';//
	//cout << "�ݹ�ʵ�ּ������"<< b.getTreeDepthR(b.getRoot()) << '\n '
	// << "�ǵݹ�ʵ�ּ������" << b.getTreeDepthNR(b.getRoot()) << ' ';
	//cout << "�ݹ�ʵ�ּ����Ϊһ�ڵ����"<< b.countDegree1R(b.getRoot()) << '\n' 
	//<< "�ǵݹ�ʵ�ּ������"<< b.countDegree1NR(b.getRoot()) << '\n';


	binaryTree<int>c;
	creatTortuousBinaryTree(c);
	c.preOrderRecursion(c.getRoot()); cout << "ǰ�����" << '\n';//0123456 
	c.inOrderRecursion(c.getRoot());  cout << "�������" << '\n';//1320564
	c.postOrderRecursion(c.getRoot()); cout << "�������" << '\n';//3216540
	c.widthOrder(c.getRoot());        cout << "��ȱ���" << '\n';//0142536

	cout << c.getTreeDepthR(c.getRoot()) << "  �������(�ݹ�" << endl
		<< c.getTreeDepthNR(c.getRoot()) << "  �������(�ǵݹ�" << endl
		<< c.countDegree1R(c.getRoot()) << "  �����Ϊһ�ڵ����(�ݹ�" << endl
		<< c.countDegree1NR(c.getRoot()) << "  �����Ϊ1�ڵ����(�ǵݹ�" << endl;
}
void creatTreeFullBinaryTree(binaryTree<int>& FullBinaryTree, int depth = 0)
{
	//begin�������Զ����� ,���ڵ�Ϊ0 


	binaryTreeNode<int>** arr = new binaryTreeNode<int>*[pow(2, depth + 1) - 1];
	arr[0] = 0;
	//�����ڵ�
	for (int i = 0; i <= (pow(2, depth + 1) - 2); i++)
	{
		arr[i] = new binaryTreeNode<int>(i);
	}
	//���ӽڵ�
	for (int i = 0; i <= (int)(pow(2, depth) - 2); i++)
	{
		arr[i]->leftChild = arr[2 * i + 1];
		arr[i]->rightChild = arr[2 * i + 2];

	}


	FullBinaryTree.creatNewTree(arr[0]);
	//end



	delete[] arr;//�ͷŵ��Ǵ���ָ�������,����ָ��ָ�������δ���ͷ�

}
void creatOutBinaryTree(binaryTree<int>& binaryTree, int depth = 0)
{

	if (binaryTree.getRoot() == NULL)
	{
		binaryTree.creatNewTree(new binaryTreeNode<int>(0));
	}
	binaryTreeNode<int>* curPos = binaryTree.getRoot();

	for (int i = 1; i <= depth; i++)
	{

		curPos = curPos->leftChild = new binaryTreeNode<int>(i);
		//curPos->leftChild;
	}

	curPos = binaryTree.getRoot();
	for (int i = -1; i >= -depth; i--)
	{

		curPos = curPos->rightChild = new binaryTreeNode<int>(i);

	}

}
void creatTortuousBinaryTree(binaryTree<int>& binaryTree)
{
	if (binaryTree.getRoot() == NULL)
	{
		binaryTree.creatNewTree(new binaryTreeNode<int>(0));
	}


	binaryTreeNode<int>* curPos = binaryTree.getRoot();
	curPos = curPos->leftChild = new binaryTreeNode<int>(1);
	curPos->leftChild = new binaryTreeNode<int>(3);//
	curPos->leftChild->rightChild = new binaryTreeNode<int>(7);
	curPos = curPos->rightChild = new binaryTreeNode<int>(4);
	curPos = curPos->leftChild = new binaryTreeNode<int>(8);

	curPos = binaryTree.getRoot();
	curPos = curPos->rightChild = new binaryTreeNode<int>(2);
	curPos->rightChild = new binaryTreeNode<int>(6);//
	curPos->rightChild->leftChild = new binaryTreeNode<int>(10);
	curPos = curPos->leftChild = new binaryTreeNode<int>(5);
	curPos = curPos->rightChild = new binaryTreeNode<int>(9);







}