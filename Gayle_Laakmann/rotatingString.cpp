/*
1. Find if a string is a substring of another
2. Find if a string is a rotation of another string - e.g. waterbottle and ewaterbottl
*/

#include <iostream>

bool isSubString (std::string mainString, std::string &subString)
{
	bool flag = false;
	for (unsigned int i = 0; i < mainString.length(); i++)
	{
		unsigned int j = 0;
		if (mainString[i] == subString[j])
		{		
			while (j < subString.length() && mainString[i+j] == subString[j])
				j++;
		}
		if (j == subString.length())
			flag = true;
	}
	return flag;	
}

//another method using STL
bool isSubStringSTL (std::string mainString, std::string &subString)
{
	//if no matches were found, the function returns string::npos
	if (mainString.find(subString) != std::string::npos)
		return true;
	else
		return false;
}

bool checkRotation (std::string mainString, std::string &subString)
{
	if (mainString.length() == subString.length())
	{
		mainString = mainString + mainString;
		if (isSubString (mainString, subString))
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	std::string mainString, subString;

	std::cout << "Enter main string: ";
	getline (std::cin, mainString);

	std::cout << "Enter substring string: ";
	getline (std::cin, subString);	

	
	if (isSubStringSTL (mainString, subString))
		std::cout << "Substring is in the main string!\n";
	else
		std::cout << "Substring is NOT in the main string!\n";
	

	if (checkRotation (mainString, subString))
		std::cout << "Substring is a rotation of the main string!\n";
	else
		std::cout << "Substring is NOT a rotation of the main string!\n";


	return 0;
}