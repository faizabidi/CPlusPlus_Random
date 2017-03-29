// https://leetcode.com/problems/count-numbers-with-unique-digits/#/description

#include <iostream>
#include <map>
#include <cmath>

bool check(std::string str){
	std::map<char, int> hashmap;
	for(int i = 0; i < str.size(); i++){
		if(hashmap.find(str[i]) == hashmap.end())
			hashmap[str[i]] = 1;
		else
			hashmap[str[i]]++;
	}
	std::map<char, int>::iterator it;
	for(it = hashmap.begin(); it != hashmap.end(); it++){
		if(it->second > 1)
			return false;
	}
	return true;
}

int calculate(int n){
	n = pow(10, n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		std::string str = std::to_string(i);
		if(check(str)){
			std::cout << str << std::endl;
			ans++;
		}
	}
	return ans;
}

int main(){
	int n;
	std::cout << "Enter n:";
	std::cin >> n;

	std::cout << calculate(n);

	return 0;
}