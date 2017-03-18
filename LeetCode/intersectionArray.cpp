#include <iostream>
#include <vector>
#include <map>

void print(std::vector<int> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

std::vector<int> intersection1(std::vector<int> array1, std::vector<int> array2){
	std::vector<int> result;
    
    // Create a hashmap of both vectors
    std::map<int, int> hash1, hash2;

    // First array
    for(int i = 0; i < array1.size(); i++){
        // If not in hashmamp,add it and increase count by 1
        if(!hash1[array1[i]])
            hash1[array1[i]] = 1;
        // If already in hashmamp, increment the count
        else
            hash1[array1[i]]++;
    }

    // Second array
    for(int i = 0; i < array2.size(); i++){
        // If not in hashmamp,add it and increase count by 1
        if(!hash2[array2[i]])
            hash2[array2[i]] = 1;
        // If already in hashmamp, increment the count
        else
            hash2[array2[i]]++;
    }

    // Print botht he hashmaps
    std::map<int, int>::iterator it;
    /*for(it = hash1.begin(); it != hash1.end(); it++)
    	std::cout << it->first << ":" << it->second << std::endl;
    for(it = hash2.begin(); it != hash2.end(); it++)
    	std::cout << it->first << ":" << it->second << std::endl;*/

	for(it = hash1.begin(); it != hash1.end(); it++){
		// Check if key exists in both hashmaps
		if(hash2.find(it->first) != hash2.end()){
			int size = std::min(it->second, hash2[it->first]);
			for(int i = 0; i < size; i++)
				result.push_back(it->first);
		}
	}    
    return result;
}

int main(){
	int num1;
	std::cout << "Enter first array size:";
	std::cin >> num1;
	std::vector<int> array1(num1);
	std::cout << "Enter array1:";
	for(int i = 0; i < num1; i++)
		std::cin >> array1[i];

	int num2;
	std::cout << "Enter second array size:";
	std::cin >> num2;
	std::vector<int> array2(num2);
	std::cout << "Enter array2:";
	for(int i = 0; i < num2; i++)
		std::cin >> array2[i];

	std::vector<int> result = intersection2(array1, array2);

	for(int i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";
	std::cout << std::endl;

	return 0;
}