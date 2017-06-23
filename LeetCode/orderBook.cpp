// https://www.hackerrank.com/tests/6sb889a42s2/questions/57h3g5t29q5

#include <iostream>
#include <vector>

void print(std::vector<std::string> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

void check(std::vector<std::string> &order){
	std::string
	std::stringstream ss(order.back());
}

int main(){

	std::vector<std::string> input;
	while(true){
		std::string order;
		getline(std::cin, order);
		input.push_back(order);
		check(input);
		print(input);
	}

	return 0;
}