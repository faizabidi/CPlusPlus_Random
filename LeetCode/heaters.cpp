// https://leetcode.com/problems/heaters

#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int findClosestNumber(int num, std::vector<int> array){
	std::vector<int> tempArray;
	for(int i = 0; i < array.size(); i++)
		tempArray.push_back(std::abs(array[i] - num));
	int ans = *std::min_element(tempArray.begin(), tempArray.end());
	return ans;
}

int findRadius1(std::vector<int> houses, std::vector<int> heaters){
	int result = 0;
	std::cout << "Number of heaters = " << heaters.size() << std::endl;
	for(int i = 0; i < heaters.size(); i++){
		// Sum up everything to the left of the heater for the first heater
		// Sum up everything to the right of the heater
		// If heater to the right found, take half of the distance
		int sum_left = 0;
		int sum_right = 0;
		int temp = heaters[i];
		while(houses[temp] != heaters[i]){
			sum_left++;
			temp++;
		}
		temp++;
		// If heater exists on the right
		if(i + 1 < heaters.size()){
			std::cout << "Another heater on the right exists\n";
			while(houses[temp] != heaters[i + 1]){
				sum_right++;
				temp++;
			}
			if(sum_right % 2 == 1)
				sum_right ++;
			sum_right = sum_right / 2;
		}
		else{
			std::cout << "No more heaters on the right\n";
			// Go to the end
			while(temp < houses.size()){
				sum_right++;
				temp++;
			}
		}
		std::cout << "Left sum = " << sum_left << std::endl;
		std::cout << "Right sum = " << sum_right << std::endl;
		int temp_result = std::max(sum_left, sum_right);
		result = std::max(result, temp_result);
	}
	return result;
}

/*int findRadius2(std::vector<int> houses, std::vector<int> heaters){
	int max_house = *std::max_element(houses.begin(), houses.end());
	int min_house = *std::min_element(houses.begin(), houses.end());
	int result = 0;
	// Find the distance for each heater to the max and the min house
	for(int i = 0; i < heaters.size(); i++){
		int sum_left = std::abs(heaters[i] - min_house);
		int sum_right = std::abs(heaters[i] - max_house);
		int temp_result = std::max(sum_left, sum_right);
		result = std::max()
	}
	return result;
}*/

int findRadius3(std::vector<int> houses, std::vector<int> heaters){
	// find closest heater to for each house
	// Then take its maximum
	int ans = 0;
	for(int i = 0; i < houses.size(); i++){
		int temp = houses[i];
		int closest_heater = findClosestNumber(temp, heaters);
		std::cout << "Closest heater to " << temp << " is " << closest_heater << std::endl;
		ans = std::max(ans, closest_heater);
	}
	return ans;

}

int main(){
	int num_houses;
	std::cout << "How many houses?";
	std::cin >> num_houses;
	
	std::vector<int> houses(num_houses);
	std::cout << "Enter position of houses:";
	for(int i = 0; i < num_houses; i++)
		std::cin >> houses[i];

	int num_heaters;
	std::cout << "How many heaters?";
	std::cin >> num_heaters;

	std::vector<int> heaters(num_heaters);
	std::cout << "Enter positon of heaters:";
	for(int i = 0; i < num_heaters; i++)
		std::cin >> heaters[i];

	std::cout << findRadius3(houses, heaters) << std::endl;

	return 0;
}