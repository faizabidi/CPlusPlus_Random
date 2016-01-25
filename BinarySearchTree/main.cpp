#include <iostream>
#include <vector>
#include "BST.cpp"

int main()
{
	//std::vector<string> v = {"zero", "one", "two", "three"};

	//std::vector<int> v = {50, 76};
	//create an class object
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

	obj.RemoveNode (50);
	obj.PrintInOrder();
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	return 0;
}
