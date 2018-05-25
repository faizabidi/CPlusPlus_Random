#include <iostream>
#include <vector>
#include <map>

void printVector(std::vector<std::string> array){
	for(auto value : array)
		std::cout << value << " ";
	std::cout << std::endl;
}

void printVector2(std::vector<std::vector<int>> array){
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array[i].size(); i++)
			std::cout << array[i][j] << " ";
		std::cout << std::endl;
	}
}
// Brute force
// O(money^denominations) time and O(n) space
// https://www.coursera.org/learn/algorithmic-toolbox/lecture/GyYGv/change-problem
/****************************/
int minCoins(std::vector<int> denominations, int money){
	if(money == 0)
		return 0;
	int ans = INT_MAX;
	for(int i = 0; i < denominations.size(); i++){
		if(money >= denominations[i]){
			int ways = minCoins(denominations, money - denominations[i]) + 1;
			ans = std::min(ans, ways);
		}
	}
	return ans;
}
/****************************/
// Memoization
// O(nxn) && O(n) space
int minCoins2(std::vector<int> denominations, int money, 
				std::map<std::pair<std::vector<int>, int>, int> &hashmap){

	if(money == 0)
		return 0;
	// If already calculated before, return that
	std::pair<std::vector<int>, int> key = {denominations, money};
	auto it = hashmap.find(key);
	if(it != hashmap.end())
		return it->second;
	int ans = INT_MAX, ways;
	for(int i = 0; i < denominations.size(); i++){
		if(money >= denominations[i]){
			ways = minCoins2(
				denominations, 
				money - denominations[i], 
				hashmap
			) + 1;
			ans = std::min(ans, ways);
		}
	}
	hashmap[key] = ways;
	return ans;
}
// TODO
// Tabulation

int main(){
	//std::vector<int> denominations = {1, 3};
	//int money = 3; // Ans = 1

	//std::vector<int> denominations = {1, 2, 3};
	//int money = 4; // Ans = 2

	std::vector<int> denominations = {1, 2, 5, 10, 3, 4, 6, 12, 7, 8};
	int money = 25; // Ans = 3
	
	//std::cout << minCoins(denominations, money) << std::endl;
	
	std::map<std::pair<std::vector<int>, int>, int> hashmap;
	std::cout << minCoins2(denominations, money, hashmap) << std::endl;

	return 0;
}
