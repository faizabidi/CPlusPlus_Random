#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>

void input(std::vector<std::string> &array, int n){
	for(int i = 0; i < n; i++){
        std::string str;
        if(i == 0)
 	       std::cin.ignore();
        getline(std::cin, str);
        array.push_back(str);
    }
}

void separateString(std::string &str){
	for(int i = 0; i < str.size(); i = i + 2)
		std::cout << str[i];
	
	std::cout << "  ";

	for(int i = 1; i < str.size(); i = i + 2)
		std::cout << str[i];

	std::cout << std::endl;
}

void printString(std::vector<std::string> &array){
	for(int i = 0; i < array.size(); i++)
		separateString(array[i]);
}

int main() {
    int n;
    std::vector<std::string> array;
    
    std::cout << "Enter N:";
    std::cin >> n;

    std::cout << "Enter the strings..." << std::endl;
    input(array, n);

	printString(array);
    
    return 0;
}