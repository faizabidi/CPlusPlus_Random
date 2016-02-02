#ifndef hash_h
#define hash_h

#include <string>

class HashTab
{
public:
	//default constructor
	HashTab ();
	//hash function
	int Hash (std::string key);
	void AddItem (std::string name, std::string drink);
	int NumberOfItemsInIndex (int index);
	void PrintTable ();
	void PrintItemsInBucket (int index);
	void SearchDrink (std::string name);
	void RemoveItem (std::string name);

private:
	static const int tableSize = 4;

	struct item
	{
		std::string name;
		std::string drink;
		item *next;
	};

	//bunch of 10 item pointers each having a name, drink, and a next pointer
	item *HashTable[tableSize];
};

#endif