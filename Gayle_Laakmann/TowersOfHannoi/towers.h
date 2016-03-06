#ifndef towers_h
#define towers_h
#include <stack>

class Towers
{
public:
	//default constructor to assign all disks to 1 tower
	//assign a name to this tower
	Towers (int disks);

	void TowersOfHannoi (int, char, char, char);

	//~Towers ();
private:
	int numofOfDisks;
};
#endif