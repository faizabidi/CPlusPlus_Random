#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

void backtracking_permutations(std::string str, int start_index, int size){
    std::cout << "Running f(" << str << "," << start_index << "," 
        << size << ") *********************************" << std::endl;
    
    if(start_index == size - 1){
        std::cout << "Ans is " << str << std::endl;
        std::cout << "f(" << str << "," << start_index << "," 
        << size << ") completed!\n";
    }
    else{
        for(int i = start_index; i < size; i++){
            std::cout << "i = " << i << " to " << size - 1 << std::endl;
            std::cout << "Current i = " << i << std::endl;
            std::cout << "Start index is " << start_index << std::endl;
            std::cout << "Swapping " << str[start_index] << " with " << str[i] << std::endl;
            std::swap(str[start_index], str[i]);
            std::cout << "String now is " << str << std::endl;
            
            backtracking_permutations(str, start_index + 1, size);
            
            // Go back to the original string before swapping
            std::cout << "Swapping back to original\n";
            std::swap(str[start_index], str[i]);
            std::cout << str << std::endl;
            std::cout << "Current function is f(" << str << "," << start_index << "," << size << ") *********************************" << std::endl;    
        }
    }
    std::cout << std::endl;
}

int main(){
    std::string str = "ABC";
    backtracking_permutations(str, 0, str.size());

    return 0;
}
