#include <iostream>

void TowersOfHannoi (int disks, char source, char dest, char buffer)
{
	if (disks == 1)
	{
		std::cout << "Move disk 1 from " << source << " to " << dest << std::endl;
		return;
	}
	TowersOfHannoi (disks - 1, source, buffer, dest);
	std::cout << "Move disk " << disks << " from " << source << " to " << dest << std::endl;
	TowersOfHannoi (disks - 1, buffer, dest, source);
}

int main ()
{
	std::cout << "Enter number of disks: ";
	unsigned int n;
	std::cin >> n;
	TowersOfHannoi (n, 'A', 'B', 'C');
}