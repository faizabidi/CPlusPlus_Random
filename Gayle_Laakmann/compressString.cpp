#include <iostream>

void CompressString (std::string str)
{
	//count will keep track of the number of occurences of any given character
	unsigned int count = 1;

	//new string to store the values from the original string
	std::string str2 = "";

	//store the first letter of the string initially
	char ch = str[0];

	//run a loop from the second character of the string since first character if stored in "ch"
	for (unsigned int i = 1; i < str.length(); i++)
	{
		if (str[i] == ch)
			count++;
		else
		{
			str2 = str2 + ch + std::to_string (count);
			ch = str[i];
			count = 1;
		}
	}

	//for cases like aabbb
	str2 = str2 + ch + std::to_string (count);

	//check if after compression, the length of the string reduces or not
	if (str.length() > str2.length())
		std::cout << str2 << std::endl;
	else
		std::cout << str << std::endl;
}

int main ()
{
	std::cout << "Enter a string to compress: ";
	std::string str;
	getline (std::cin, str);

	std::cout << "Compressed string is: ";
	CompressString (str);
	return 0;
}