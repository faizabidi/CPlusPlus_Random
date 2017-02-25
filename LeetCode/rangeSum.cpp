// https://leetcode.com/problems/range-sum-query-immutable/?tab=Description

class NumArray {
public:
    // Using dynamic programming
    NumArray(vector<int> nums){
	    array = nums;;
	    for(int i = 0; i < nums.size(); i++){
	        int sum = 0;
	        for(int j = i; j < nums.size(); j++){
	            sum += nums[j];
	            hashmap[std::make_pair(i, j)] = sum;
	        }
	    }
	}
	int sumRange(int i, int j){
	    pair<int, int> key = make_pair(i, j);
	    return hashmap[key];
	}
    // Using brute force
    /*
    // Constructor
    NumArray(vector<int> nums){
        array = nums;
    }
    
    int sumRange(int i, int j){
        int sum = 0;
        for(int a = i; a <= j; a++)
            sum += array[a];
        return sum;
    }*/

private:
    vector<int> array;
    map<std::pair<int, int>, int> hashmap;
};