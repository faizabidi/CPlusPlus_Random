//best, average and worst case scenario is O(n x n)

#include <iostream>
#include <vector>

class Sort
{
private:
	std::vector<int> array;

public:
	Sort():array(0){}
	
	void Swap (int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void GetArray()
	{
		int num = 0;
		while (num != -1)
		{
			std::cin>>num;
			if (num != -1)
				array.push_back(num);
		}
		std::cout<<"Elements in the array is "<<array.size()<<std::endl;
	}

	void PrintArray()
	{
		for (size_t i = 0; i < array.size(); i++)
			std::cout<<array[i]<<" ";
		std::cout<<std::endl;
	}

	void SelectionSort()
	{
		
		for (size_t i = 0; i < array.size() - 1; i++)
		{
			//index of the smallest element
			//initialize with the first element
			int index_smallest = i;

			//check the entire array for the smallest element
			//on each pass, we will check all elements to the right of the sorted list
			//that's why, it's j = i + 1
			for (size_t j = i + 1; j < array.size(); j++)
			{
				if (array[j] < array[index_smallest])
					index_smallest = j;
			}

			//swap values only if needed
			if (i != index_smallest)
				Swap (&array[i], &array[index_smallest]);
		}
	}
};

int main()
{
	Sort obj;
	std::cout<<"Enter array (-1 to stop)\n";
	obj.GetArray();

	std::cout<<"Selection sorted sorted array is\n";
	obj.SelectionSort();
	obj.PrintArray();

	return 0;
}