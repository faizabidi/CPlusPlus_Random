#include <iostream>
#include <vector>

/**********************************/
// Brute force
// O(n*n)
int smallest_subarray_sum(std::vector<int> array){
    int sum = INT_MAX;
    for(int i = 0; i < array.size(); i++){
        int temp = 0;
        for(int j = i; j < array.size(); j++){
            temp += array[j];
            if(temp < sum)
                sum = temp;
        }
    }
    return sum;
}
/**********************************/
// DP solution
// Kadane's algorithm
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// O(n)
int smallest_subarray_sum_kadane(std::vector<int> array){
    int min_ending_sofar = INT_MAX, min_ending_here = 0;
    int start_index = 0, end_index = 0, temp_index = 0;
    for(int i = 0; i < array.size(); i++){
        min_ending_here += array[i];
        if(min_ending_here > 0){
            min_ending_here = 0;
            temp_index++;
        }
        else{
            if(min_ending_here < min_ending_sofar){
                min_ending_sofar = min_ending_here;
                start_index = temp_index;
                end_index = i;
            }
        }
    }
    // If min_ending_here is still zero that means all the numbers in the array were positive. In which case, return the smallest number in the array
    if(min_ending_here == 0){
        std::cout << std::distance(array.begin(), 
                        std::min_element(array.begin(), array.end())) << std::endl;
        return *std::min_element(array.begin(), array.end());
    }
    std::cout << start_index << ", " << end_index << std::endl;
    return min_ending_sofar;
}

int main(){
    //std::vector<int> array = {-2, -3, 4, -1, -2, 1, 5, -3}; // Ans = -5
    //std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Ans = -5
    //std::vector<int> array = {-5, -4, 3}; // Ans = -9
    std::vector<int> array = {5, 3, 4}; // Ans = 3
    std::cout << smallest_subarray_sum_kadane(array) << std::endl;

    return 0;
}
