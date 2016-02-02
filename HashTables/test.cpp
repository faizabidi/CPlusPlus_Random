#include <iostream>

int hash (std::string key)
{
	unsigned long hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++)
		//multiplying by a random number 13 to diversify the hash function
		hash = (hash + (int)key[i]) * 13;
	
	index = hash % 30;
	return index;
}

int main ()
{
	std:: cout << hash ("faiz");
	//hash ("faiz");
	return 0;
}
