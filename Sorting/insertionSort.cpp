//best case is when list is already sorted. Performance will be O(n)
//average case is O (n x n)
//worst case is when list is reveresed. Performance will be O(n x n)

#include <iostream>
#include <vector>

class InsertionSort
{
private:
	std::vector<int> array;
public:
	InsertionSort ():array(0){}
	void GetList (int num);
	void PrintList ();
	void Sort ();
};

int main()
{
	InsertionSort obj;
	std::cout<<"Enter array (-1 to exit)\n";
	int num;
	obj.GetList(num);
	
	std::cout<<"List entered is\n";
	obj.PrintList();

	std::cout<<"Sorted list is\n";
	obj.Sort();
	obj.PrintList();

	return 0;
}

void InsertionSort::GetList(int num)
{
	while (num != -1)
	{
		std::cin>>num;
		if (num != -1)
			array.push_back(num);
	}
	std::cout<<"Size of list is "<<array.size()<<std::endl;
}

void InsertionSort::PrintList()
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}

void InsertionSort::Sort()
{
	for (size_t i = 1; i < array.size(); i++)
	{
		int value = array[i];
		int hole = i;
		while (hole > 0 && array[hole - 1] > value)
		{
			array[hole] = array[hole - 1];
			hole--;
		}
		array[hole] = value;
	}
}