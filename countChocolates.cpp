#include<iostream>

template <class T>
int CountChocolates(T money)
{
	//since 3 chocolates for 1 rupee
	money = money * 3;

	//initialize chocolates equal to the money
	T chocolates = money;

	//remainder to keep check of the wrappers
	int remainder = 0;

	//we don't want to add the wrappers left at the end, which...
	//...would not be greater than 2 else at least 1 chocolate can be bought
	while (money > 2)
	{
		//1 chocolate for every 3 wrappers
		chocolates += (money / 3);
		
		//take remainder only if count is greater than 2
		if (money > 2)
			remainder = money % 3;

		//divide by 3 since this money here is actually wrapper count and...
		//...3 wrappers give 1 chocolate
		money = money / 3;
		
		//update money by adding the int value obtained of money + wrappers count
		money += remainder;
	}
	return chocolates;
}

int main()
{
	int n;
	while (true)
	{
		std::cout<<"Enter rupees:";
		std::cin>>n;
		std::cout<<"Chocolate count is: "<<CountChocolates(n)<<std::endl;
	}
	return 0;
}