/*
Check of a string has all unique characters
*/

#include <iostream>
#include <string>

//complexity is O (n)
bool UniqueCharacters (std::string str)
{
	//total unique chracters are 128
	if (str.length() > 128)
		return false;
	else
	{
		bool check[256] = {false};
		for (unsigned int i = 0; i < str.length(); i++)
		{
			int asciiVal = str[i];
			//update check array with each incremented character
			if (check[asciiVal] == false)
				check[asciiVal] = true;
			else if (check[asciiVal] == true)
				return false;
		}
		return true;
	}
}

int main ()
{
	std::string str;
	std::cout << "Enter a string: ";
	std::getline (std::cin,str);
	bool test = UniqueCharacters (str);
	if (test)
		std::cout << "It's unique!\n";
	else
		std::cout << "Not unique!\n";

	return 0;
}