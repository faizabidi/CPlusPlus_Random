#include <iostream>
#include <vector>

int maxPoints (std::vector<int> toss)
{
	std::vector<int> sum;

	for (unsigned int i = 0; i < toss.size (); i++)
	{
		sum.push_back(toss[i]);
		for (unsigned int j = i + 1; j < toss.size (); j++)
		{
			if (toss[i] == toss[j])
				sum[i] = sum[i] + toss[j];
		}
	}

	//std::vector<int>::iterator result = std::max_element (sum.begin (), sum.end ());

	auto biggest = std::max_element (sum.begin (), sum.end ());
	
	return *biggest;
}

int main ()
{
	int num;
	std::vector<int> array;

	std::cout << "Enter the 5 values obtained on the dice: ";

	for (unsigned int i = 0; i < 5; i++)
	{
		std::cin >> num;
		array.push_back (num);
	}

	std::cout << maxPoints (array) << std::endl;

	return 0;
}