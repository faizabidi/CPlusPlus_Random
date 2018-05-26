#include <iostream>
#include <vector>
#include <map>

/****************************/
// Helper functions
template<typename T>
void printVector(std::vector<T> array){
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
/****************************/
// Brute force
// O(money^denominations) time and O(n) space
// https://www.coursera.org/learn/algorithmic-toolbox/lecture/GyYGv/change-problem
/****************************/
int minCoins(std::vector<int> denominations, int money){
	if(money == 0)
		return 0;
	int ans = INT_MAX - 1;
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
// O(nxm) && O(nxm) space
int minCoins2(std::vector<int> denominations, int money, 
				std::map<std::pair<std::vector<int>, int>, int> &hashmap){

	if(money == 0)
		return 0;
	// If already calculated before, return that
	std::pair<std::vector<int>, int> key = {denominations, money};
	auto it = hashmap.find(key);
	if(it != hashmap.end())
		return it->second;
	int ans = INT_MAX - 1, ways;
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
/****************************/
// Tabulation
// O(nxm) time and O(n) space
// https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/
int minCoins3(std::vector<int> denominations, int money){
	std::vector<int> sumArray(money+1, INT_MAX-1);
	sumArray[0] = 0;
	for(int i = 0; i < denominations.size(); i++){
		int currentCoin = denominations[i];
		for(int j = 1; j < sumArray.size(); j++){
			// Proceed only if the value of the current coin is less or 
			// equal to the value of j
			if(currentCoin <= j)
				sumArray[j] = std::min(sumArray[j], 
											1+sumArray[j - currentCoin]);
		}
	}
	//printVector(sumArray);
	return sumArray[money];
}


int main(){
	//std::vector<int> denominations = {4, 3};
	//int money = 7; // Ans = 2

	//std::vector<int> denominations = {1, 2, 3};
	//int money = 4; // Ans = 2

	std::vector<int> denominations = {1, 2, 5, 10, 3, 4, 6, 12, 7, 8};
	int money = 25; // Ans = 3
	
	std::cout << minCoins(denominations, money) << std::endl;
	
	std::map<std::pair<std::vector<int>, int>, int> hashmap;
	std::cout << minCoins2(denominations, money, hashmap) << std::endl;

	std::cout << minCoins3(denominations, money) << std::endl;	

	return 0;
}
