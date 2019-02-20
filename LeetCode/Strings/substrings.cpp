#include <iostream>
#include <vector>

// O(nxn) time && O(1) space
void printAllSubstrings(std::string str){
    for(int i = 0; i < str.size(); i++){
        std::string temp;
        for(int j = i; j < str.size(); j++){
            temp += str[j];
            std::cout << temp << std::endl;
        }
    }
}

int main(){
    std::string str = "abc";
    printAllSubstrings(str);

    return 0;
}