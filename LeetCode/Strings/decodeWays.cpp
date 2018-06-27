// https://leetcode.com/problems/decode-ways/description/

#include <iostream>
#include <vector>
#include <unordered_set>

void getWays_helper(std::string str, int index, std::string temp,
                                std::unordered_set<std::string> &hashset){

    if(index == str.size()){
        // Add to hashset if not exists
        if(hashset.find(temp) == hashset.end())
            hashset.insert(temp);
        return;
    }
    // Add the current index character
    temp +=str[index];
    // Include it as a single character
    getWays_helper(str, index+1, temp+',', hashset);
    // Include it and the next character
    if(index+1 < str.size())
        getWays_helper(str, index+2, temp+str[index+1]+',', hashset);
}

int getWays(std::string str){
    int index = 0;
    std::unordered_set<std::string> hashset;
    std::string temp = "";
    getWays_helper(str, index, temp, hashset);
    int ways = filterHashset(hashset);
    return ways;
}


int main(){
    //std::string str = "123"; // Ans = 3

    std::cout << getWays(str) << std::endl;

    return 0;
}