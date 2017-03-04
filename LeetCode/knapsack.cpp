#include <iostream>
#include <vector>
#include <map>

// Using recursion
int calculate_KnapSack(int items, std::vector<int> weights, 
			std::vector<int> values, int max_weight){

	// Base case - when max_weight is zero or items is 0
	if(items == 0 || max_weight == 0)
		return 0;

	// If weight of current item > max_weight
	// Exclude it
	if(weights[items - 1] > max_weight)
		return calculate_KnapSack(items - 1, weights, values, max_weight);

	// Else, return maximum of the two case
	// 1 - V(i) is included
	// 2 - V(i) not included
	return std::max(values[items - 1] + 
				calculate_KnapSack(items - 1, weights, values, max_weight - weights[items - 1]), 
				calculate_KnapSack(items - 1, weights, values, max_weight));
}

// Using dynamic programming
int calculate_KnapSack2(int items, std::vector<int> weights, 
			std::vector<int> values, int max_weight){

	// Build a hashmap
	int k[items + 1][max_weight + 1];
	for(int n = 0; n <= items; n++){
		for(int w = 0; w <= max_weight; w++){
			// If max_weight is 0 or items is 0
			if(w == 0 || n == 0)
				k[n][w] = 0;
			// If weight is more than the max_weight
			else if(weights[w] > max_weight)
				k[n][w] = k[n - 1][w];
			// 
			else
				k[n][w] = 
					std::max(values[n - 1] + k[n - 1][w - weights[n - 1]],
								k[n - 1][w]);
		}
	}
	return k[items][max_weight];
}

int main(){
	int items;
	std::cout << "# items:";
	std::cin >> items;

	std::vector<int> weights(items);
	std::cout << "Enter weights:";
	for(int i = 0; i < items; i++)
		std::cin >> weights[i];

	std::vector<int> values(items);
	std::cout << "Enter values:";
	for(int i = 0; i < items; i++)
		std::cin >> values[i];	

	int max_weight;
	std::cout << "Enter the MAX weight:";
	std::cin >> max_weight;

	std::cout << calculate_KnapSack2(items, weights, values, max_weight) << " ";

	return 0;
}