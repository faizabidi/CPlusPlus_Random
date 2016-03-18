//average case performance is O(nlog n)
//worst case is O(n x n), which is avoided almost always with randomized quick sort 
//it's better than merge sort since it is in-place (constant extra memory),...
//...and probability of average case if high

#include <iostream>
#include <vector>

void GetData(std::vector<int> &array);

int Partition (std::vector<int> &array, int start, int end);

void Sort (std::vector<int> &array, int start, int end);

void PrintData(std::vector<int> &array);

int main()
{
	std::cout<<"Enter an array (-1 to exit)\n";
	std::vector<int> array;
	GetData(array);

	std::cout<<"Entered array is\n";
	PrintData(array);
	
	std::cout<<"After sorting, array becomes\n";//<<array.size() - 1;
	Sort (array, 0, array.size() -1);
	PrintData(array);
	return 0;
}

void GetData(std::vector<int> &array)
{
	int num;
	while (num != -1)
	{
		std::cin>>num;
		if (num != -1)
			array.push_back(num);
	}
}

void PrintData(std::vector<int> &array)
{
	for (std::vector<int>::iterator i = array.begin(); i < array.end(); i++)
		std::cout<<*i<<" ";
	std::cout<<std::endl;
}

int Partition (std::vector<int> &array, int start, int end)
{
	//let the pivot be the last element
	int pivot = array[end];
	//std::cout<<"Pivot is "<<pivot;
	//initialize the index to the beginnning of the array
	int partitionIndex = start;

	//check all elements except the pivot
	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot)
			std::swap (array[i], array[partitionIndex++]);
	}

	//swap not with pivot but the last element in the array
	std::swap (array[partitionIndex], array[end]);
	return partitionIndex;
}

void Sort (std::vector<int> &array, int start, int end)
{
	//base condition
	if (start < end)
	{
		//index of the pivot
		int partitionIndex = Partition (array, start, end);

		//left subarray
		Sort (array, start, partitionIndex - 1);
		//right subarray
		Sort (array, partitionIndex + 1, end);
	}
}