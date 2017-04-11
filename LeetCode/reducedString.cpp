#include <iostream>
#include <string>

std::string reduce(std::string str){
	for(int i = 0; i + 1 < str.size(); i++){
		if(str[i] == str[i+1])
			str.erase(i, 2);
		std::cout << str;
	}
	return str;
}

int main(){
	std::string str;
	std::cout << "Enter string:";
	std::cin >> str;

	std::string reduced_string = reduce(str);
	//std::cout << reduced_string << std::endl;

	return 0;
}