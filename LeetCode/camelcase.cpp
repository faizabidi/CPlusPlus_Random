// https://www.hackerrank.com/challenges/camelcase

#include <vector>
#include <iostream>
#include <algorithm>

int calculate(std::string str){
	int count = 0;
	if(str.size() != 0)
		count++;
	for(int i = 0; i < str.size(); i++){
		if(int(str[i]) >= 65 &&  int(str[i]) <= 90)
			count++;
	}
	return count;
}

int main(){
    std::string str;
    std::cin >> str;
    std::cout << calculate(str) << std::endl;
    return 0;
}
