#include <iostream>
#include <vector>
#include <map>

class Solution{
public:
	void printHashmap(std::map<std::pair<int, int>, int> hashmap){
		std::map<std::pair<int, int>, int>::iterator it;
		for(it = hashmap.begin(); it != hashmap.end(); it++)
			std::cout << it->first.first << "," << it->first.second << ":" << it->second << std::endl;
	}

	void printVector(std::vector<std::vector<int> > array){
		for(int i = 0; i < array.size(); i++){
			for(int j = 0; j < array[i].size(); j++)
				std::cout << array[i][j] << " ";
			std::cout << std::endl;
		}
	}

    std::vector<std::vector<int> > fourSum(std::vector<int> nums, int target){
    	std::vector<std::vector<int> > ans;
    	// Find out all possible sums (a+b) with each number
    	// and store in a hashmap
    	std::map<std::pair<int, int>, int> hashmap;
    	for(int i = 0; i < nums.size(); i++){
    		for(int j = 0; j < nums.size(); j++){
    			if(j != i){
	    			int sum = nums[i] + nums[j];
    				hashmap[std::make_pair(i,j)] = sum;
    			}
    		}
    	}
    	//std::cout << "Hashmap is \n";
    	printHashmap(hashmap);
    	// Now, find two values in the hashmap that sum to target
    	std::map<int, bool> hashmap_check;
    	std::map<std::pair<int, int>, int>::iterator it1,it2;
    	for(it1 = hashmap.begin(); it1 != hashmap.end(); it1++){
    		for(it2 = it1; it2 != hashmap.end(); it2++){
    			if(it1 != it2 && it1->second + it2->second == target){
    				std::cout << it1->first.first << ":" << it1->first.second
    							<< "," << it2->first.first << ":" << it2->first.second << std::endl;
					std::vector<int> temp;
					if( (it1->first.first != it2->first.first) &&
					    (it1->first.first != it2->first.second) &&
					    (it1->first.second != it2->first.first) &&
					    (it1->first.second != it2->first.second) ){
						// Check if sum not already in the check hashmap
						int sum = it1->first.first + it1->first.second + 
							it2->first.first + it2->first.second;
						if(hashmap_check.find(sum) == hashmap_check.end()){
							hashmap_check[sum] = true;
							temp.push_back(nums[it1->first.first]);
							temp.push_back(nums[it1->first.second]);
							temp.push_back(nums[it2->first.first]);
							temp.push_back(nums[it2->first.second]);
							std::sort(temp.begin(), temp.end());
							ans.push_back(temp);
						}
					}
    			}
    		}
    	}
    	std::cout << "Vector is\n";
    	printVector(ans);
		return ans;
	}
};

int main(){
	std::cout << "How many numbers? ";
	int n;
	std::cin >> n;
	
	std::cout << "Enter array:";
	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	std::cout << "Enter target:";
	int target;
	std::cin >> target;

	Solution obj1;
	obj1.fourSum(array, target);

	return 0;
}