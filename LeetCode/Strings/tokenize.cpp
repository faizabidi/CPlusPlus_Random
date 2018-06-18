// http://ysonggit.github.io/coding/2014/12/16/split-a-string-using-c.html

#include <iostream>
#include <sstream>
#include <vector>

template<typename T>
void print(std::vector<T> array){
    for(auto value : array)
        std::cout << value << std::endl;
}

// Note that there may be empty tokens
std::vector<std::string> tokenize(std::string str, char delimeter){
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string buffer;
    while(std::getline(ss, buffer, delimeter))
        tokens.push_back(buffer);

    return tokens;
}

int main(){
    std::string str = "faiz abidi is a boy who live in Morrisville.";
    std::vector<std::string> tokens = tokenize(str, ' ');
    print(tokens);

    return 0;
}