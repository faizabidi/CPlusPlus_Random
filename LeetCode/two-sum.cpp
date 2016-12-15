// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    std::vector<int> twoSum_Hash(std::vector<int> &nums, int target){
        std::vector<int> indices;
        std::unordered_map<int, int> hash;
        //unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int numToFind = target - nums[i];
            std::cout << "Number to find is " << numToFind << std::endl;

            //if key found
            if(hash.find(numToFind) != hash.end()){
                indices.push_back(hash[numToFind]);
                indices.push_back(i);
                std::cout << nums[i] << " found" << std::endl;
                break;
            }
            else
            {
                std::cout << nums[i] << " not found. Adding to hash map\n";
                hash[nums[i]] = i;
            }
        }
        return indices;
    }
};

int main(){
	Solution obj1;
	std::vector<int> array, indices;
	int num, target;
	
	std::cout << "Enter an array of numbers (-9999 to exit): ";
	while(num != -9999){
		std::cin >> num;
		if(num != -9999)
			array.push_back(num);
	}

	std::cout << "Enter target: ";
	std::cin >> target;

	indices = obj1.twoSum_Hash(array, target);
    for(int i = 0; i < indices.size(); i++)
	   std::cout << indices[i] << " ";
    std::cout << std::endl;

    return 0;
}