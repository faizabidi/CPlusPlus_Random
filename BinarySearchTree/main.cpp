#include <iostream>
#include <vector>
#include "BST.cpp"

int main()
{
	int array[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	
	BST obj;

	for (int i = 0; i < 16; i++)
		obj.AddLeaf (array[i]);

	std::cout<<"Inorder traversal\n";
	obj.PrintInOrder();

	std::cout<<std::endl;
	std::cout<<std::endl;

	for (int i = 0; i < 16; i++)
		obj.PrintChildren(array[i]);

	std::cout<<"Smallest element in the tree is "<<obj.SmallestNode()<<std::endl;

	std::cout<<"Height of tree is: "<<obj.HeightOfTree();
	std::cout<<std::endl;

	std::cout << "Number of nodes in the tree = " << obj.numberOfNodes ();
	std::cout<<std::endl;

	std::cout << "Sum of all nodes = " << obj.sumOfNodesRecursive ();
	std::cout<<std::endl;
	std::cout << "Sum of all nodes = " << obj.sumOfNodesIterative ();
	std::cout<<std::endl;

	std::cout << "Lowest common ancesstor of node 32 and node 3 is " << obj.lowestCommonAncesstor (32, 3);
	std::cout<<std::endl;

	std::cout << "Lowest common ancesstor of node 4 and node 80 is " << obj.lowestCommonAncesstor (4, 80);
	std::cout<<std::endl;

	std::cout << "Shortest distnace between node 50 and node 80 is " << obj.distanceBetweenNodes (50, 80);
	std::cout<<std::endl;

	std::cout << "Shortest distnace between node 4 and node 87 is " << obj.distanceBetweenNodes (4, 87);
	std::cout<<std::endl;
	
	obj.RemoveNode (50);
	obj.PrintInOrder();
	
	std::cout<<std::endl;

	std::cout << "Number of leaf nodes in this tree = " << obj.leafCount ();
	std::cout<<std::endl;

	return 0;
}
