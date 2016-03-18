/*
reverse a null terminated string
*/

#include <iostream>

void reverse (char *str)
{
	//end pointer to store the string
	char *end = str; //both pointers pointing to the same location initially
	
	//reach the end of the string	
	if (str) //equivalent to if (str != NULL) or making sure str points to something
	{
		while (*end) //equivalent to while (*end != '\0') making sure it's not a null character
			end++;
	}
	
	//end will point to the null character initially
	end--;
	
	//swap the values till the middle - first with last and so on
	while (str < end)
	{
		char temp = *str;
		*str++ = *end;
		*end-- = temp;
	}
}

int main ()
{
	char *str;
	std::cout << "Enter a string: ";
	std::cin >> str;
	reverse (str);
	std::cout << "Reversed string entered is: " << str;

	return 0;
}
