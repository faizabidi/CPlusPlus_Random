// https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description

class Solution{
public:
    // O(nxn)
    int findPairs1(vector<int> nums, int k){
        std::map<std::pair<int, int>, bool> hashmap;
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if( (std::abs(nums[i] - nums[j]) == k) && hashmap.find(std::make_pair(nums[i], nums[j])) == hashmap.end()){
                    result++;
                    hashmap[std::make_pair(nums[i], nums[j])] = true;
                    hashmap[std::make_pair(nums[j], nums[i])] = true;
                    std::cout << "i = " << i << "\n" << "j = " << j << std::endl;
                }
            }
        }
        return result;
    }
    // O(n)
    int findPairs2(vector<int> nums, int k){
        std::map<int, int> hashmap;
        int result = 0;
        // Insert all elements in the hashmap
        for(int i = 0; i < nums.size(); i++)
            hashmap[nums[i]]++;
        std::map<int, int>::iterator it;
        if(k > 0){
            for(it = hashmap.begin(); it != hashmap.end(); it++){
                if(hashmap.find(it->first + k) != hashmap.end()){
                    std::cout << it->first << std::endl;
                    result++;
                }
            }
        }
        else if(k == 0){
            for(it = hashmap.begin(); it != hashmap.end(); it++){
                if(it->second > 1)
                    result++;
            }
        }
        else if(k < 0)
            return 0;
        return result;
    }
};