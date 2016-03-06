#include <stack>
#include "towers.h"

Towers::Towers (int disks)
{
	numofOfDisks = disks;
}

void Towers::TowersOfHannoi (int disks, char src, char dest, char buffer)
{
	if (disks == 1)
	{
		std::cout << "Move disk 1 from " << src << " to " << dest << std::endl;
		return;
	}

	Towers::TowersOfHannoi (disks - 1, src, buffer, dest);
	std::cout << "Move disk " << disks << " from " << src << " to " << dest << std::endl;
	Towers::TowersOfHannoi (disks - 1, buffer, dest, src);
}


