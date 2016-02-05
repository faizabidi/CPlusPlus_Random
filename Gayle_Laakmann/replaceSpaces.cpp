/*
Replace spaces in a string with "%20"
*/

#include <iostream>
#include <string>
#include <vector>

void ReplaceSpaces (std::string str)
{
	//new string to store the old string and replace spaces
	std::string newStr;

	for (unsigned int i = 0; i < str.length (); i++)
	{
		//if space found
		if (str[i] == ' ')
			newStr.append ("%20");
		else
			//just add the characters of the original string into the new string
			newStr.push_back (str[i]);
	}

	std::cout << newStr;
}

int main ()
{
	std::cout << "Enter a string: ";
	std::string str;
	getline (std::cin, str);

	ReplaceSpaces (str);

	return 0;
}