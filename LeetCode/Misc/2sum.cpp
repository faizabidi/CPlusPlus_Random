#include <iostream>
#include <vector>
#include <set>

void printVector(std::vector<int> array){
    for(auto value : array)
        std::cout << value << " ";
    std::cout << std::endl;
}

// Without hashset
// O(nlog(n)) time and O(1) space
std::vector<int> twoSum(std::vector<int> array, int target){
    int low = 0, high = array.size() - 1;
    std::sort(array.begin(), array.end());
    std::cout << "Sorted vector is\n";
    printVector(array);
    while(low < high){
        int sum = array[low] + array[high];
        if(sum == target)
            return {array[low], array[high]};
        if(sum < target)
            low++;
        else
            high--;
    }
    return {};
}

// With hashset
// O(n) time and O(n) space
std::vector<int> twoSum2(std::vector<int> array, int target){
    std::set<int> hashset;
    for(int i = 0; i < array.size(); i++){
        int sumNeeded = target - array[i];
        // Check if in hashset
        if(hashset.find(sumNeeded) != hashset.end())
            return {array[i], sumNeeded};
        // Else, add to hashet
        hashset.insert(array[i]);
    }
    return {};
}
int main(){
    std::vector<int> array = {3,2,4,4,2};
    int target = 7;
    std::vector<int> pair = twoSum(array, target);
    printVector(pair);
    std::vector<int> pair2 = twoSum2(array, target);
    printVector(pair2);
    return 0;
}
