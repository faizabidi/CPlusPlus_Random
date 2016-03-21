#include <iostream>

#define MAX_SIZE 1000000

int multiply (long long result[], int matrix_size, int x)
{
	int carry = 0;

	for (int i = 0; i < matrix_size; i++)
	{
		int product = result[i] * x + carry;
		result[i] = product % 10;
		carry = product / 10;
	}

	//store carry in the matrix
	while (carry > 0)
	{
		result[matrix_size] = carry;
		carry = 0;
		matrix_size++;
	}

	return matrix_size;
}

int factorial (int num)
{
	long long result[MAX_SIZE];
	long long matrix_size = 1;
	int count = 0;

	result[0] = 1;

	for (int i = 2; i <= num; i++)
		matrix_size = multiply (result, matrix_size, i);


	for (int i = 0; i < matrix_size; i++)
	{	
		if (result[i] == 0)
			count++;
		else
			break;
	}
	
	return count;
}

int main ()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;

	std::cout << "Trailing zero's = " << factorial (num);

	return 0;
}