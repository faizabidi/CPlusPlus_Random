/*
check if two strings are permuttion of each other
*/

#include <iostream>
#include <algorithm>

bool PermutationCheck (std::string &str1, std::string &str2)
{
	//sort the two strings
	std::sort (str1.begin(), str1.end());
	std::sort (str2.begin(), str2.end());

	if (str1 == str2)
		return true;
	else
		return false;
}

int main ()
{
	std::string str1, str2;
	
	std::cout << "Enter string 1: ";
	getline (std::cin, str1);

	std::cout << "Enter string 2: ";
	getline (std::cin, str2);

	if (PermutationCheck (str1, str2))
		std::cout << "The two strings are permutation of each other!\n";
	else
		std::cout << "The two strings are NOT permutation of each other!\n";

	return 0;
}
