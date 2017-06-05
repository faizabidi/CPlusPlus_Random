// https://www.hackerrank.com/challenges/funny-string

#include <vector>
#include <iostream>

std::string calculate(std::string str){
	std::string str_orig = str;
	std::reverse(str.begin(), str.end());
	for(int i = 1; i < str.size(); i++){
		if(std::abs((str[i] - 0) - (str[i - 1] - 0)) != std::abs((str_orig[i] - 0) - (str_orig[i - 1] - 0)))
			return "Not Funny";
	}
	return "Funny";
}

int main(){
	int n;
    std::cin >> n;  

    for(int i = 0; i < n; i++){
    	std::string str;
    	std::cin >> str;
    	std::cout << calculate(str) << std::endl;
    }

    return 0;
}
