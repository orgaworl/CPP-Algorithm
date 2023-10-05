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
	//cout << "递归实现计算深度"<< a.getTreeDepthR(a.getRoot()) << '\n '
	// << "非递归实现计算深度"<< a.getTreeDepthNR(a.getRoot()) << ' ';
	//cout<< "递归实现计算度为一节点个数" << a.countDegree1R(a.getRoot())<< '\n' 
	//<< "非递归实现计算深度" << a.countDegree1NR(a.getRoot()) << '\n';


	//binaryTree<int>b;
	//creatOutBinaryTree(b, 2);
	//b.preOrderRecursion(b.getRoot()); cout << '\n';
	//b.inOrderRecursion(b.getRoot());  cout << '\n';
	//b.postOrderRecursion(b.getRoot()); cout << '\n';
	//b.widthOrder(b.getRoot());        cout << '\n';//
	//cout << "递归实现计算深度"<< b.getTreeDepthR(b.getRoot()) << '\n '
	// << "非递归实现计算深度" << b.getTreeDepthNR(b.getRoot()) << ' ';
	//cout << "递归实现计算度为一节点个数"<< b.countDegree1R(b.getRoot()) << '\n' 
	//<< "非递归实现计算深度"<< b.countDegree1NR(b.getRoot()) << '\n';


	binaryTree<int>c;
	creatTortuousBinaryTree(c);
	c.preOrderRecursion(c.getRoot()); cout << "前序遍历" << '\n';//0123456 
	c.inOrderRecursion(c.getRoot());  cout << "中序遍历" << '\n';//1320564
	c.postOrderRecursion(c.getRoot()); cout << "后序遍历" << '\n';//3216540
	c.widthOrder(c.getRoot());        cout << "广度遍历" << '\n';//0142536

	cout << c.getTreeDepthR(c.getRoot()) << "  计算深度(递归" << endl
		<< c.getTreeDepthNR(c.getRoot()) << "  计算深度(非递归" << endl
		<< c.countDegree1R(c.getRoot()) << "  计算度为一节点个数(递归" << endl
		<< c.countDegree1NR(c.getRoot()) << "  计算度为1节点个数(非递归" << endl;
}
void creatTreeFullBinaryTree(binaryTree<int>& FullBinaryTree, int depth = 0)
{
	//begin创建测试二叉树 ,根节点为0 


	binaryTreeNode<int>** arr = new binaryTreeNode<int>*[pow(2, depth + 1) - 1];
	arr[0] = 0;
	//创建节点
	for (int i = 0; i <= (pow(2, depth + 1) - 2); i++)
	{
		arr[i] = new binaryTreeNode<int>(i);
	}
	//连接节点
	for (int i = 0; i <= (int)(pow(2, depth) - 2); i++)
	{
		arr[i]->leftChild = arr[2 * i + 1];
		arr[i]->rightChild = arr[2 * i + 2];

	}


	FullBinaryTree.creatNewTree(arr[0]);
	//end



	delete[] arr;//释放的是储存指针的数组,其中指针指向的区域未被释放

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