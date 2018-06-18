// https://leetcode.com/problems/goat-latin/description/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <typename T>
void print(std::vector<T> array){
    for(auto value : array)
        std::cout << value << " ";
    std::cout << std::endl;
}

// O(nxn) time and O(nxn) space
std::string toGoatLatin(std::string str){
    // Containerize the string
    std::vector<std::string> array;
    std::stringstream ss(str);
    std::string buf;
    while(ss >> buf)
        array.push_back(buf);

    std::string temp;
    std::vector<char> vowel = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 
                                                            'O', 'u', 'U'};
    for(int i = 0; i < array.size(); i++){
        temp += 'a';
        std::string word = array[i];
        // If a consonant
        if(std::find(vowel.begin(), vowel.end(), word[0]) == vowel.end()){
            char ch = word[0];
            // Delete the first character and append to the end
            word.erase(0, 1);
            word += ch;
        }
        word += "ma";
        word += temp;
        array[i] = word;
    }
    // Clear the original string
    str.clear();
    // Store everything back to str
    for(int i = 0; i < array.size(); i++)
        if(i != array.size() - 1)
            str += array[i] + " ";
        else
            str += array[i];
    
    return str;
}

int main(){
    std::string str = "I speak Goat Latin";
    //str = toGoatLatin(str);
    std::string str2 = "Chandani";
    std::reverse(str2.begin(), str2.begin()+2);
    std::cout << str2 << std::endl;


    return 0;
}
