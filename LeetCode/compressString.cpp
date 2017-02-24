#include <iostream>

std::string compress(std::string str){
	std::string result;
	for(int i = 0; i < str.size(); i++){
		int count = 1;
		for(int j = i; j < str.size(); j++){
			if(str[i] == str[j + 1])
				count++;
			else{
				result += str[i] + std::to_string(count);
				i = j;
				break;
			}
		}
	}
	return result;
}

int main(){
	std::string str;
	std::cin >> str;
	std::cout << compress(str);
	return 0;
}