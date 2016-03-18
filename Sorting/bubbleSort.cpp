//in the first pass, the heaviest element goes to the top
//in the second pass, the second heaviest goes to the second most top place


//average and worst case performace is O(n x n)
//best performance when all is sorted is O(n)

#include <iostream>
#include <vector>

//function to swap values
//need to pass by reference to sort the original values and not just these copies
void Swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort (std::vector<int> &array)
{
	std::cout<<"Elements in the array: "<<array.size()<<std::endl;

	//flag to check if array is already sorted
	int flag = 0;

	//comparisons will be done n times
	for (int i = 0; i < array.size() - 1; i++)
	{
		//compare elemet to the next element, and swap if condition is true
		for(int j = 0; j < array.size() - 1; j++)
		{	
			if (array[j] > array[j+1])
			{
				Swap(&array[j], &array[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}

//function to print the array
void PrintArray (std::vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
}

int main()
{
	std::cout<<"Enter array to be sorted (-1 to end)\n";

	std::vector<int> array;
	int num = 0;
	while (num != -1)
	{
		std::cin>>num;
		if (num != -1)
			//add elements to the vector container
			array.push_back(num);
	}

	//sort the array
	BubbleSort(array);

	std::cout<<"Sorted array is\n";
	PrintArray(array);

	return 0;
}