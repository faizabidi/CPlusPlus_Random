#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << "{" << array[i] << "}\n";
}

// Using recursion - O(2^n)
/*************************/
void powerSet_helper(std::string str, std::string temp, int index, 
    std::vector<std::string> &ans){

    if(index == str.size()){
        ans.push_back(temp);
        return;
    }

    // Include
    powerSet_helper(str, temp + str[index], index + 1, ans);

    // Exclude
    powerSet_helper(str, temp, index + 1, ans);
}

std::vector<std::string> powerSet(std::string str){
    std::vector<std::string> set;
    powerSet_helper(str, "", 0, set);

    return set;
}
/*************************/
// Using iteration - O(2^n)
std::vector<std::string> powerSet2(std::string str){
    std::vector<std::string> set;
    // Insert the empty set
    set.push_back("");
    for(int i = 0; i < str.size(); i++){
        // Iterate through all the elements in the array and add the new character to all of them
        int size = set.size();
        for(int j = 0; j < size; j++)
            set.push_back(set[j] + str[i]);
    }
    return set;   
}
/*************************/
// Recursive approach
// O(2^n)


int main(){
    std::string str = "abc";
    //std::vector<std::string> set = powerSet(str);
    std::vector<std::string> set = powerSet2(str);
    printVector(set);

    return 0;
}
