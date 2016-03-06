#include <iostream>
#include "towers.cpp"

int main ()
{
	std::cout << "Enter number of disks: ";
	unsigned int numberOfDisks;
	std::cin >> numberOfDisks;

	Towers obj1 (numberOfDisks);

	obj1.TowersOfHannoi (numberOfDisks, 'A', 'B', 'C');
	
	return 0;
}