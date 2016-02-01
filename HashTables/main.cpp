/* 
Hash table is an array, coupled with a hash function
lookup takes O(1) as average case, and O(n) as worst case
Insertion and deletion is also O (1) in average case, and O(n) in worst case
Space complexity is O(n) is average and worst case

In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that.

We have implemented separate chaining in this exampple where each bucket is independent, and has some sort of list of...
....entries with the same index. The time for hash table operations is the time to find the bucket (which is constant).. 
...plus the time for the list operation.
*/


#include <iostream>
#include <string>
#include "hash.h"
#include "hash.cpp"

int main ()
{

	HashTab obj;
	std::string name;

	obj.AddItem ("Faiz", "Pepsi");
	obj.AddItem ("Shabih", "Coke");
	obj.AddItem ("Faisal", "Lemon Juice");
	obj.AddItem ("Faraz", "Fanta");
	obj.AddItem ("Ayush", "Puly Orange");
	obj.AddItem ("Praneet", "Beer");
	obj.AddItem ("Alice", "Crush");
	obj.AddItem ("Andre", "Ahlan");
	obj.AddItem ("Tuna", "Tequila");
	obj.AddItem ("Sarthak", "DrPepper");

	obj.PrintTable ();

	//obj.PrintItemsInBucket (5);

	//std::cout << obj.Hash ("faiz") << std::endl;
	//obj.SearchDrink("Praneet");
	while (name != "exit")
	{
		std::cout << "Delete item? ";
		std::cin >> name;

		if (name != "exit")
			obj.RemoveItem (name);
 	}

 	obj.PrintTable ();

	return 0;
}