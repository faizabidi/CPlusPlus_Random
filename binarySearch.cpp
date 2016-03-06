#include <iostream>
#include <vector>

void binarySearch (std::vector<int> array, int min, int max, int value)
{
	if (min > max)
	{	
		std::cout << value << " not found";
		return;
	}

	int mid = ( min + max ) / 2;

	if (array[mid] == value)
		std::cout << value << " found at position " << mid + 1;
	else if (array[mid] > value)
		 binarySearch (array, min, mid - 1, value);
	else if (array[mid] < value)
		 binarySearch (array, mid + 1, max, value);
}

int main ()
{
	std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	binarySearch (v, 0, 9, 98);

	return 0;
}