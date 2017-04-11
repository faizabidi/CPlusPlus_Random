#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void print(std::map<std::string, int> hashmap){
	std::map<std::string, int>::iterator it;
	for(it = hashmap.begin(); it != hashmap.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
}

void printVector(std::vector<std::string> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

void calculate(std::vector<std::string> array){
	std::vector<std::string> ans;
	// Create a hashmap and store in it
	std::map<std::string, int> hashmap;
	std::vector<int> values;
	for(int i = 0; i < array.size(); i++){
		// Check if value already in hashmap
		if(hashmap.find(array[i]) == hashmap.end()){
			// Add to hashmap
			hashmap[array[i]] = 1;
		}
		else
			hashmap[array[i]]++;		
	}
	print(hashmap);
	std::map<std::string, int>::iterator it;
	// Store the values of the hashmap in a vector
	for(it = hashmap.begin(); it != hashmap.end(); it++)
		values.push_back(it->second);
	// Sort the vector
	std::sort(values.begin(), values.end());
	// Store the last three values of the array
	int largest = values[values.size() - 1];
	int second_largest = values[values.size() - 2];
	int third_largest = values[values.size() - 3];
	
	std::cout << "Largest = " << largest << std::endl;
	std::cout << "Second largest = " << second_largest << std::endl;
	std::cout << "Third largest = " << third_largest << std::endl;
	// We only want 3 items
	int count = 0;

	std::vector<std::string> temp1;
	for(it = hashmap.begin(); it != hashmap.end(); it++){
		if(it->second == largest && count < 3){
			count++;
			temp1.push_back(it->first);
		}
	}

	std::sort(temp1.begin(), temp1.end());
	printVector(temp1);

	// Print second largest if count != 3
	if(count < 3 && second_largest != largest){
		std::vector<std::string> temp2;
		for(it = hashmap.begin(); it != hashmap.end(); it++){
			if(it->second == second_largest && count < 3){
				count++;
				temp2.push_back(it->first);
			}
		}
		std::sort(temp2.begin(), temp2.end());
		printVector(temp2);
	}

	// If count is still not 3
	if(count < 3 && third_largest != second_largest){
		std::vector<std::string> temp3;
		for(it = hashmap.begin(); it != hashmap.end(); it++){
			if(it->second == third_largest && count < 3){
				count++;
				temp3.push_back(it->first);
			}
		}
		std::sort(temp3.begin(), temp3.end());
		printVector(temp3);
	}
	//printVector(ans);
}

int main(){
	int n;
	std::cin >> n;
	if(n == 0)
		return 0;
	std::vector<std::string> array(n);
	std::cin.ignore();
	for(int i = 0; i < n; i++)
		getline(std::cin, array[i]);

	calculate(array);

	return 0;
}