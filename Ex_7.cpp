#include <stdlib.h>       
#include"binarySearchTree.hpp"
//#include"minHeap.hpp"
using namespace std;

void Ex_7()
{

	binarySearchTree<int> bst;
	int temp;
	int times = 0;
	cout << "ÊäÈë:" << endl << "  ";
	while (cin.peek() != '\n' && cin >> temp)
	{
		bst.insertNode(temp);
	}
	cout << "Êä³ö:" << endl << "  ";
	bst.preOrder(bst.getRoot());
}
