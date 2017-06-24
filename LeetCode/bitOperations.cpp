#include <iostream>

int main(){
	/* 
	Left shift means shifting bits to the left
	0001 << 1 = 0010 (decimal equivalent of 1 left shift 1 gives 2)
	Left shift can also be thought of as (decimal number * pow(2, number_of_bit_shifted))
	Note that the bits shifted does not mean they get added back in the front. They get discarded forever.
	*/
	std::cout << (1 << 1) << std::endl; // Should be 1 * 2 = 2
	std::cout << (2 << 3) << std::endl; // Should be 2 * 8 = 16
	/*
	//Right shift means shifting bits to the right
	0001 >> 1 = 0000
	Right shift can also be though of as (decimal number / 2);
	Note that the bits shifted does not mean thay they get added to the back. They get discarded forever.
	*/
	std::cout << (1 >> 1) << std::endl; // Should be (1 / 2) = 0;
	std::cout << (2 >> 1) << std::endl; // Should be (2 / 2) = 1;

	return 0;
}