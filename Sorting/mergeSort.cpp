//worst and average case performance is O(nlog n)
//best case O(n)
//it's not in-place because it doesn;t take contant amount ot extra memory
//memory depends on the number of elements

#include <iostream>
#include <vector>

void GetData (std::vector<int> &array);
void DisplayData (std::vector<int> array);
void Merge (std::vector<int> &left, std::vector<int> &right, std::vector<int> &array);
void Sort (std::vector<int> &array);

int main()
{
	std::cout<<"Enter array (-1 to exit)\n";
	std::vector<int> array;
	GetData(array);

	std::cout<<"Size of array is "<<array.size()<<std::endl;
	
	std::cout<<"Entered array is\n";
	DisplayData(array);
	
	std::cout<<"Sorted array is\n";
	Sort(array);
	DisplayData(array);

	return 0;
}

void GetData(std::vector<int> &array)
{
	int num = 0;
	while (num != -1)
	{
		std::cin>>num;
		if (num != -1)
			array.push_back(num);
	}
}

void DisplayData(std::vector<int> array)
{
	int i = 0;
	while (i < array.size())
	{
		std::cout<<array[i]<<" ";
		i++;
	}
	std::cout<<std::endl;
}

void Merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &array)
{
	//remove all elements from the vector
	array.clear();

	//i for the left array, j for the right
	int i = 0, j = 0;

	while (i < left.size() && j < right.size())
	{
		if (left.at(i) <= right.at(j))
			array.push_back(left.at(i++));
		else
			array.push_back(right.at(j++));
	}
	
	//if some elememts still left in either left or right vectors
	while (i < left.size())
		array.push_back(left.at(i++));

	while (j < right.size())
		array.push_back(right.at(j++));
}

void Sort(std::vector<int> &array)
{
	//base condition
	if(array.size() < 2)
		return;

	//store elements in the left and right sub lists
	std::vector<int> left(array.begin(), array.begin() + array.size() / 2);
	std::vector<int> right(array.begin() + array.size() / 2, array.end());

	//recursive functions
	Sort(left);
	Sort(right);
	Merge(left, right, array);
}