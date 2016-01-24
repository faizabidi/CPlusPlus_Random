#include <iostream>
#include <vector>

template <class T, class U>
void PrintOpenLockers (T lockerCount, U vector)
{	
	int i = 0, count = 0;
	//assume 0 for open, and 1 for closed
	int open = 0, closed = 1;

	while (i < lockerCount) 
	{
		if (vector[i] == open)
		{
			std::cout <<i + 1<<" ";
			count++;
		}
		i++;
	}
	std::cout<<"\nTotal open lockers = "<<count;
	std::cout<<std::endl;
}

template <class T, class U>
void Lockers (T lockerCount, T studentCount, U vector)
{
	//0 for open, 1 for closed
	int open = 0, closed = 1;
	
	//all lockers closed initially
	for (size_t i = 0; i < lockerCount; i++)
		vector.push_back(closed);

	//starting from the first student
	for (size_t i = 1; i <= studentCount; i++)
	{
		for (size_t j = i; j <= lockerCount; j = j + i)
			vector[j - 1] == open ? vector[j - 1] = closed : vector[j - 1] = open;
	}
	PrintOpenLockers (lockerCount, vector);
}

int main()
{
	int lockercount, studentCount;
	std::vector<int> vector;
	std::cout<<"Enter number of lockers: ";
	std::cin>>lockercount;

	std::cout<<"Enter number of students: ";
	std::cin>>studentCount;

	std::cout<<"Open lockers will be\n";
	Lockers(lockercount, studentCount, vector);
	return 0;
}