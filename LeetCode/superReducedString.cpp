// https://www.hackerrank.com/challenges/reduced-string

#include <vector>
#include <iostream>

std::string reducedString(std::string str){
	std::string ans;
	for(int i = 0; i < str.size(); i++){
		std::cout << "i = " << i << std::endl;
		if(str[i] == str[i + 1] && i + 1 < str.size()){
			std::string reducedString;
			int j = i + 2;
			i = -1;
			// Re-populate the reduced string
			while(j < str.size()){
				reducedString += str[j];
				j++;
			}
			str = reducedString;
			std::cout << "New String = " << str << std::endl;
		}
		else{
			ans += str[i];
			std::cout << "Ans = " << ans << std::endl;
		}
	}
	return ans;
}

std::string reducedString2(std::string str){
	for(int i = 0; i < str.size(); i++){
		std::cout << "i = " << i << std::endl;
		std::cout << "str[i] = " << str[i] << " and str[i+1] = " << str[i+1] << std::endl;
		if(str[i] == str[i + 1] && i + 1 < str.size()){
			str.erase(i, 2);
			i = -1;
			std::cout << "Updated str = " << str << std::endl;
			std::cout << "Size of str = " << str.size() << std::endl;
		}
		std::cout << "i = " << i << std::endl;
	}
	return str.size() > 0 ? str : "Empty String";
}


int main() {
    std::string str;
    std::cin >> str;
    std::cout << reducedString2(str);
    return 0;
}
