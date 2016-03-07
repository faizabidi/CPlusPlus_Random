#include <iostream>

std::string decode (std::string cipherText, int shift)
{
	for (unsigned int i = 0; i < cipherText.length (); i++)
	{
		if (int (cipherText[i]) - shift < 65)
			cipherText[i] = char ( int (cipherText[i]) - 65 + 90 - shift );
		else
			cipherText[i] = char ( int (cipherText[i]) - shift );
	}
	return cipherText;
}

int main ()
{
	std::string str;
	int shift;

	std::cout << "Enter cipher text: ";
	std::cin >> str;

	std::cout << "Shift by how many characters? ";
	std::cin >> shift;

	std::cout << decode (str, shift) << std::endl; 
	return 0;
}