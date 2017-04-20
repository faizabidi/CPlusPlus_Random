#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums){
        int i = 0, j = 1;
        int count = 0;
        while(i <  nums.size() && j < nums.size()){
            if(nums[i] == nums[j])
                j++;
            else{
                std::swap(nums[i+1], nums[j]);
                i++;
                j++;
            }
        }
        return i + 1;
    }
};

int main(){
    std::vector<int> array = {1,1,2};
    Solution obj1;
    std::cout << obj1.removeDuplicates(array);
    return 0;
}