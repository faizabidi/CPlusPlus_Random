#include <iostream>
#include "node.cpp"

int main ()
{
	LinkedList list1, list2, list3;
	list1.appendNodeBack (2);
	list1.appendNodeBack (3);
	list1.appendNodeBack (5);
	list1.appendNodeBack (4);
	
	list2.appendNodeBack (5);
	list2.appendNodeBack (6);
	list2.appendNodeBack (7);
	list2.appendNodeBack (8);

	list1.printList ();
	std::cout << list1.SumOfNodes (list1) << std::endl;

	list2.printList ();
	std::cout << list2.SumOfNodes (list2) << std::endl;

	unsigned int sum = list1.SumOfNodes (list1) + list2.SumOfNodes (list2);

	//convert the number to string
	std::string str = std::to_string (sum);

	//append integer value to the new list
	for (unsigned int i = 0; i < str.length (); i++)
		list3.appendNodeBack (int (str[i] - '0'));

	std::cout << "The new list becomes\n";
	list3.printList();

	return 0;
}