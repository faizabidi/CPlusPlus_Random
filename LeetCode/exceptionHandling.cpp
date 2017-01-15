// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer

#include <iostream>
#include <cstdlib>

void check(std::string str){
	try{
		std::cout << stoi(str);
	}
	catch (std::logic_error e) {
        std::cerr << "Bad String";
    }
}

int main(){
	std::string str;
	std::cout << "Enter a string:";
	getline(std::cin, str);

	check(str);

	return 0;
}