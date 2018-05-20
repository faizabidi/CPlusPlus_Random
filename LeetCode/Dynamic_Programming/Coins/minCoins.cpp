#include <iostream>
#include <vector>

void printVector(std::vector<std::string> array){
	for(auto value : array)
		std::cout << value << " ";
	std::cout << std::endl;
}

// Brute force
// O(money^denominations) time and O(n) space
/****************************/
int minCoins_helper(std::vector<int> denominations, int index, int money, 
						std::string temp, std::vector<std::string> &array){

	if(money == 0){
		array.push_back(temp);
		return 1;
	}
	if(money < 0)
		return 0;
	if(index == denominations.size())
		return 0;

	// Include it
	int include = minCoins_helper(denominations, index, 
						money - denominations[index], 
						temp+std::to_string(denominations[index]), array);

	// Exclude it
	int exclude = minCoins_helper(denominations, index+1, money, temp, array);

	return (include + exclude);
}

int minCoins(std::vector<int> denominations, int money){
	std::vector<std::string> array;
	int ways = minCoins_helper(denominations, 0, money, "", array);
	std::cout << "Possible solutions = " << ways << std::endl;
	if(array.size() == 0)
		return -1;
	// Go through all the solutions and find the minimum length
	int ans = INT_MAX;
	for(int i = 0; i < array.size(); i++){
		if(array[i].size() < ans)
			ans = array[i].size();
	}
	return ans;
}
/****************************/
// TODO - Memoization and Tabulation


int main(){
	//std::vector<int> denominations = {1, 3};
	//int money = 3, curr_index = 0;

	std::vector<int> denominations = {1, 2, 3};
	int money = 4, curr_index = 0;

	std::cout << minCoins(denominations, money) << std::endl;

	return 0;
}