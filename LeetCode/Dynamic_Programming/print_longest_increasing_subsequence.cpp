// https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/

#include <iostream>
#include <vector>

void print_list(std::vector<int> array){
    if(array.size() == 0)
        return;
    std::vector<std::vector<int>> lis_array(array.size());
    lis_array[0].push_back(array[0]);
    for(int i = 1; i < array.size(); i++){
        for(int j = 0; j < i; j++){
            if(array[i] > array[j] && 
                lis_array[i].size() < lis_array[j].size() + 1)

                lis_array[i] = lis_array[j];
        }
        lis_array[i].push_back(array[i]);
    }
    // Print the array from lis_array that is biggest in size
    // Find out the max index first
    int max_index = 0, max_size = 0;
    for(int i = 0; i < lis_array.size(); i++){
        if(lis_array[i].size() > max_size){
            max_size = lis_array[i].size();
            max_index = i;
        }
    }
    // Print the vector at max index
    std::vector<int> lis_ans = lis_array[max_index];
    for(int i = 0; i < lis_ans.size(); i++)
        std::cout << lis_ans[i] << " ";
    std::cout << std::endl;
}

int main(){
    //std::vector<int> array = {3, 2, 6, 4, 5, 1};
    std::vector<int> array = {10, 1, 3, 2, 20};
    print_list(array);

    return 0;
}
