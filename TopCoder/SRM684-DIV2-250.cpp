#include <iostream>
#include <vector>
#include <algorithm>

bool checkChar (char ch, std::string str)
{
	for (unsigned int i = 0; i < str.length (); i++)
	{
		if (ch == str[i])
			return false;
	}
	return true;
}

int count (std::string str, int k)
{
	std::string str2;
	std::vector<int> array;
	int sum = 0;

	for (unsigned int i = 0; i < str.length (); i++)
	{	
		//check if character already parsed
		if (checkChar (str[i], str2))
		{
			str2.push_back (str[i]);
			int count = 0;

			for (unsigned int j = 0; j < str.length (); j++)
			{
				if (str[j] == str[i])
					count++;
			}
			array.push_back (count);
		}
	}
	
	std::vector<int>::iterator largest;
	int index;

	for (unsigned int i = 0; i < k; i++)
	{
		//find the largest
		largest = std::max_element (array.begin (), array.end ());

		//find the index of the largest
		index = std::distance (array.begin (), largest);

		//replace the largest by largest - 1
		array[index] = *largest - 1;
	}

	for (unsigned int i = 0; i < array.size (); i++)
		sum = sum + array[i] * array[i];

	return sum;
}


int main ()
{
	std::string str;
	int k;

	std::cout << "Enter a string: ";
	std::cin >> str;

	std::cout << "Enter the value of k: ";
	std::cin >> k;

	std::cout << count (str, k) << std::endl;

	return 0;
}