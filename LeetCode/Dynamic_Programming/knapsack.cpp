// REF: http://www.techiedelight.com/0-1-knapsack-problem/

#include <iostream>
#include <vector>
#include <climits>
#include <map>

class Solution{
public:
	// Time complexity is exponential (2^n)
	// Simple recursion
	int knapsack(std::vector<int> weight, std::vector<int> values, int total_weight, int size){

		// Base case is when the number of items left is zero or the weight becomes 0
		if(total_weight == 0 || size < 0)
			return 0;

		// If weight becoms negative, we want to reject this condition. Since we are doing sum = sum[size] + ....., in order to reject this value, we return INT_MIN to cancel out
		if(total_weight < 0)
			return INT_MIN;

		// We either include the item or exclude the item
		// If we include, total weight = total weight - weight of this item
		// If we include, value = value + value of this item
		int include = values[size] + knapsack(weight, values, total_weight - weight[size], size - 1);

		int exclude = knapsack(weight, values, total_weight, size - 1);

		// Return the max. of the two as the answer
		return std::max(include, exclude);
	}	

	// Use dynamic programming
	// Time complexity = O(size * total weight)
	int knapsack2(std::vector<int> weight, std::vector<int> values, int total_weight, int size){

		// Base case
		if(size < 0 || total_weight == 0)
			return 0;

		// If the weight become negative, reject this value
		if(total_weight < 0)
			return INT_MIN;

		// Check if it has already been calculated before. If not, calculate it
		// This is bascially memoization
		std::string key = std::to_string(size) + 
					'|' + std::to_string(total_weight);
		if(map.find(key) == map.end()){
			int include = values[size] + 
			knapsack(weight, values, total_weight - weight[size], size - 1);
			
			int exclude = knapsack(weight, values, total_weight, size - 1);

			map[key] = std::max(include, exclude); 
		}
		return map[key];
	}

	void printMap(){
		std::map<std::string, int>::iterator it;
		for(it = map.begin(); it != map.end(); it++)
			std::cout << it->first << ":" << it->second;
		std::cout << std::endl;
	}

private:
	std::map<std::string, int> map;
};

int main(){
    //std::vector<int> weight = {1,2,3};
    std::vector<int> weight = {10,20,30};
    //std::vector<int> values = {20,5,10,40,15,25};
    //std::vector<int> values = {3,2,1};
    //std::vector<int> weight = {1,2,3,8,7,4};
    std::vector<int> values = {60,100,120};

    //int total_weight = 4;
    //int total_weight = 10;
    int total_weight = 50;


    Solution obj1;

    std::cout << obj1.knapsack2(weight, values, total_weight, 
    	weight.size() - 1) << std::endl;

    obj1.printMap();


	return 0;
}
