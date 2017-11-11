// https://www.hackerrank.com/challenges/gem-stones/problem

#include <iostream>
#include <vector>
#include <algorithm>

void removeDuplicates(std::string &str){
    std::sort(str.begin(), str.end());
    auto last = std::unique(str.begin(), str.end());
    str.erase(last, str.end());
}

int gemstones(std::vector <std::string> arr){
    // If nothing in the vector
    if(arr.size() == 0)
        return 0;
    // If only 1 string in the vector
    if(arr.size() == 1){
        // Return the number of unique elements
        // We can do this using hashmaps
        // Or, let's try std::unique
        // Erase the duplicates
        removeDuplicates(arr[0]);
        return arr[0].size();
    }
    else{
        std::string str = arr[0];
        removeDuplicates(str);
        for(auto i = 1; i < arr.size(); i++){
            // Find the common elements between the first two string and then move onto comparing this with the next and so on.
            std::string str1 = arr[i];
            removeDuplicates(str1);
            std::string common = "";
            auto j = 0;
            while(j < str.size() && j < str1.size()){
                if(str[j] == str1[j])
                    common += str[j];
                j++;
            }
            str = common;
        }
        return str.size();
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::string> arr(n);
    for(auto arr_i = 0; arr_i < n; arr_i++)
       std::cin >> arr[arr_i];
    
    auto result = gemstones(arr);
    std::cout << result << std::endl;
    return 0;
}
