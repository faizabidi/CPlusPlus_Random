#include <iostream>
#include <vector>
#include <map>

// Recurive approach
int coinWays(std::vector<int> denominations, int curr_index, int money){
	int ways = 0;

	// Base cases
	if(money < 0)
		return 0;
	if(money == 0)
		return 1;
	if(curr_index == denominations.size())
		return 0;

	// Include it
	ways += coinWays(denominations, curr_index, 
						money - denominations[curr_index]);
	// Exclude it
	ways += coinWays(denominations, curr_index+1, money);

	return ways;
}

// DP approach
// In the recursive approach, the function gets called several times just like
// we saw in the fibonacci series. What if we store the values in the hashmap?
// Memoization ot top-down
// O(nxm) time + O(nxm) space (space of the hashmap)
int coinWays2(std::vector<int> denominations, int curr_index, 
			int money, std::map<std::pair<int, int>, int> &hashmap){

	int ways = 0;

	// Base cases
	if(money < 0)
		return 0;
	if(money == 0)
		return 1;
	if(curr_index == denominations.size())
		return 0;

	std::pair<int, int> key = {curr_index, money};
	// Check if we have already calculated this before
	auto it = hashmap.find(key);	
	if(it != hashmap.end()){
		std::cout << "Saved duplicate computation\n";
		return it->second;
	}
	// Otherwise, calculate it and add to hashmap
	// Include the number
	ways += coinWays2(denominations, curr_index, 
					money - denominations[curr_index], hashmap);

	// Exclude the number
	ways += coinWays2(denominations, curr_index+1, money, hashmap);
	
	// Add to hashmap
	hashmap[key] = ways;
	return ways;

}

// Tabulation method
// https://www.youtube.com/watch?v=jaNZ83Q3QGc
// O(nxm) time && O(n) space
int coinWays3(std::vector<int> denominations, int sum){
	std::vector<int> array(sum + 1, 0);
	for(int i = 0; i < denominations.size(); i++){
		int currCoin = denominations[i];
		for(int j = 0; j < array.size(); j++){
			if(j == 0)
				array[j] = 1;
			if(j >= currCoin){
				array[j] += array[j - currCoin];
			}
		}
	}
	return array[sum];
}

int main(){
	//std::vector<int> denominations = {1, 3};
	//int money = 3, curr_index = 0; // Ans = 2

	std::vector<int> denominations = {1, 2, 3};
	int money = 4, curr_index = 0; // Ans = 4

	//std::cout << coinWays(denominations, curr_index, money) << std::endl;
	std::map<std::pair<int, int>, int> hashmap;
	std::cout << coinWays2(denominations, curr_index, money, hashmap)
																<< std::endl;

	std::cout << coinWays3(denominations, money) << std::endl;
	return 0;
}
