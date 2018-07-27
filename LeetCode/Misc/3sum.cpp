// https://leetcode.com/problems/3sum/description/
// https://fizzbuzzed.com/top-interview-questions-1/#twopointer
// https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution

#include <iostream>
#include <vector>
#include <set>

void printMatrix(std::vector<std::vector<int>> matrix){
    std::cout << "Triplets are\n";
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void printVector(std::vector<int> array){
    for(auto value : array)
        std::cout << value << " ";
    std::cout << std::endl;
}

// Using sorting
// O(nlog(n)+O(nxn)) = O(nxn) time and O(n) space complexity 
std::vector<std::vector<int>> threeSum(std::vector<int> array, int target){
    std::vector<std::vector<int>> ans;
    if(array.size() < 2)
        return ans;
    std::sort(array.begin(), array.end());
    std::cout << "Sorted array is\n";
    printVector(array);
    for(int i = 0; i < array.size() - 2; i++){
        int low = i+1, high = array.size() - 1;
        while(low < high){
            if(array[i] + array[low] + array[high] == target){
                ans.push_back({array[i], array[low], array[high]});
                while(array[low] == array[low+1] && low+1 < array.size())
                    low++;
                while(array[high] == array[high-1] && high-1 >= 0)
                    high--;
                low++, high--;
            }
            else if(array[i] + array[low] + array[high] > target)
                high--;
            else
                low++;
        }
        // Fix this index and find all solutions with array[i];
        while(array[i] == array[i+1] && i+1 < array.size() - 2)
            i++;
    }
    return ans;
}

int main(){
    std::vector<int> array = {-1, 0, 1, 2, -1, -4};
    //std::vector<int> array = {0,0,0,0,0};
    //std::vector<int> array = {3,0,-2,-1,1,2};
    //std::vector<int> array = {-1,0,1,2,-1,-4};
    int target = 0;
    std::vector<std::vector<int>> triples = threeSum(array, target);
    printMatrix(triples);
    return 0;
}
