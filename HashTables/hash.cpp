#include <string>
#include "hash.h"

//default constructor
HashTab::HashTab () 
{
	//initialize the item pointers values
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "Empty!";
		HashTable[i]->drink = "Empty!";
		HashTable[i]->next = NULL;
	}
}

int HashTab::Hash (std::string key)
{
	unsigned long hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++)
		//multiplying by a random number 13 to diversify the hash function
		hash = (hash + (int)key[i]) * 13;
	
	index = hash % tableSize;
	return index;
}

void HashTab::AddItem (std::string name, std::string drink)
{
	//find the location or the index or the "bucket" of where should we insert this item
	int index = Hash (name);

	//if there is no item at that place (no collision)
	if (HashTable[index]->name == "Empty!")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
		return;
	}

	//if there are items at that bucket already (it's a collision)
	//create a new item
	item *newItem = new item;
	newItem->name = name;
	newItem->drink = drink;
	newItem->next = NULL;

	//temp pointer will point to the first element at that bucket or index or position
	item *temp = HashTable[index];
	
	//add the new item to the list at the end
	//parse to the end of the list
	while (temp->next != NULL)
		temp = temp->next;

	//make a link
	temp->next = newItem;
}

int HashTab::NumberOfItemsInIndex (int index)
{
	int count = 0;

	//if no items at that index
	if (HashTable[index]->name == "Empty!")
		return count;
	else
	{
		item *temp = HashTable[index];
		do
		{
			count++;
			temp = temp->next;
		}
		while (temp != NULL);

		return count;
	}
}

void HashTab::PrintTable ()
{
	int NumberOfElements;
	for (int i = 0; i < tableSize; i++)
	{
		//calculate the item count for each index or bucket
		NumberOfElements = NumberOfItemsInIndex(i);
		std::cout << "------------------------------------\n";
		std::cout << "Bucket " << i << std::endl;
		std::cout << HashTable[i]->name << std::endl;
		std::cout << HashTable[i]->drink << std::endl;
		std::cout << "Number of items in that bucket = " << NumberOfElements << std::endl;
		std::cout << "------------------------------------\n";
	}
}

void HashTab::PrintItemsInBucket (int index)
{
	if (HashTable[index]->name == "Empty!")
	{
		std::cout << "Nothing in bucket " << index << std::endl;
		return;
	}

	//point temp to the place where the index is
	item *temp = HashTable[index];
	std::cout << "Items in bucket " << index << " are as below\n";
	while (temp != NULL)
	{
		std::cout << "------------------------------------\n";
		
		std::cout << temp->name << std::endl;
		std::cout << temp->drink << std::endl;
		std::cout << "------------------------------------\n";
		temp = temp->next;
	}
}

void HashTab::SearchDrink (std::string name)
{
	//find the bucket in which that name is stored
	int bucket = Hash (name);

	//check if the name if beyond the table size
	bool foundName = false;

	//string to store the name of the drink
	std::string drink;


	//temp pointer to point to the top item in the bucket
	item *temp = HashTable[bucket];

	while (temp != NULL)
	{
		if (temp->name == name)
		{
			foundName = true;
			drink = temp->drink;
			break;
		}		
		//else, increment the pointer to point to the next item
		temp = temp->next;
	}

	if (foundName)
		std::cout << name << "'s favourite drink is " << drink << std::endl;
	else
		std::cout << name << " is not in the table\n";
}

void HashTab::RemoveItem (std::string name)
{
	//bucket will store the bucket or the index in which "name" exists
	unsigned int bucket = Hash (name);

	item *deletePtr;

	//Case 0 : if the bucket is empty
	if (HashTable[bucket]->name == "Empty!")
	{
		std::cout << name <<" not found in the hash table\n";
		return;
	}

	//Case 1 : if the bucket is not empty, contains only 1 item, which is a match
	if (HashTable[bucket]->name == name && HashTable[bucket]->next == NULL)
	{		
		//make the values the default values without actually deleting anything
		HashTable[bucket]->name = "Empty!";
		HashTable[bucket]->drink = "Empty!";
		std::cout << name << " deleted from the hash table\n";
		return;
	}

	//Case 2 : if the bucket is not empty, and the first item is a match, and there are more items in that bucket
	if (HashTable[bucket]->name == name && HashTable[bucket]->next != NULL)
	{
		deletePtr = HashTable[bucket];
		HashTable[bucket] = HashTable[bucket]->next;
		delete deletePtr;
		std::cout << name << " deleted from the hash table\n";
		return;
	}

	//Case 3 : if the bucket is not empty and the first item is not a match
	if (HashTable[bucket]->name != name && HashTable[bucket]->next != NULL)
	{
		item *nextt = HashTable[bucket]->next;
		item *prev = HashTable[bucket];

		//search for the item
		while (nextt != NULL && nextt->name != name)
		{
			prev = nextt;
			nextt = nextt->next;
		}

		//Case 3a : if item not found
		if (nextt == NULL)
		{
			std::cout << name << " not found in the hash table\n";
			return;
		}

		//Case 3b : if item found
		deletePtr = nextt;
		prev->next = nextt->next;
		delete nextt;
		std::cout << name << " deleted from the hash table\n";
	}
}