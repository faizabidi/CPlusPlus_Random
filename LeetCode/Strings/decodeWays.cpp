// https://leetcode.com/problems/decode-ways/description/

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force
// O(2^n) time
bool isValid(std::string str){
    for(int i = 0; i < str.size(); i++){
        std::string temp = "";
        // Extract number before the comma
        while(str[i] != ','){
            temp += str[i];
            i++;
        }
        // Check if the value is between 1 and 26
        // And temp doesn't start with a 0
        int num = std::stoi(temp);
        if(num < 1 || num > 26 || temp[0] == '0')
            return false;
    }
    return true;
}

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
    if(isValid(temp)){
        // Include it as a single character
        getWays_helper(str, index+1, temp+',', hashset);
        // Include it and the next character
        if(index+1 < str.size())
            getWays_helper(str, index+2, temp+str[index+1]+',', hashset);
    }
}

int numDecodings(std::string str){
    int index = 0;
    std::unordered_set<std::string> hashset;
    std::string temp = "";
    getWays_helper(str, index, temp, hashset);
    return hashset.size();
}
/*************************/
// TODO: DP solution

int main(){
    //std::string str = "123"; // Ans = 3
    //std::string str = "0"; // Ans = 0
    //std::string str = "10"; // Ans = 1
    std::string str = "101"; // Ans = 1
    std::cout << numDecodings(str) << std::endl;

    return 0;
}
