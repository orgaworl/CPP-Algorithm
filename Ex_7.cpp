#include <stdlib.h>       
#include"binarySearchTree.hpp"
//#include"minHeap.hpp"
using namespace std;

void Ex_7()
{

	binarySearchTree<int> bst;
	int temp;
	int times = 0;
	cout << "����:" << endl << "  ";
	while (cin.peek() != '\n' && cin >> temp)
	{
		bst.insertNode(temp);
	}
	cout << "���:" << endl << "  ";
	bst.preOrder(bst.getRoot());
}
