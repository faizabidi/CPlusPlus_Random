// https://www.hackerrank.com/challenges/two-characters

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

bool check(std::string str){
	std::map<char, int> map;
	for(int i = 0; i < str.size(); i++)
		map[str[i]]++;
	
	// If there are more than two characters, return false
	if(map.size() != 2)
		return false;
	
	// Check if it matches the patttern xyxyx or yxyxy
	for(int i = 1; i < str.size(); i++){
		if(str[i - 1] == str[i])
			return false;
	}

	// Else, it satisfies the criteria
	return true;
}

int calculate(int n, std::string str){
	int ans = 0;

	// Create a hashmap to find out the distinct characters
	std::map<char, int> map;
	for(int i = 0; i < str.size(); i++)
		map[str[i]]++;

	// Delete all but two characters and then check if it satisfies the condition
	std::map<char, int>::iterator it1, it2;
	for(it1 = map.begin(); it1 != map.end(); it1++){
		for(it2 = map.begin(); it2 != map.end(); it2++){
			char x = it1->first;
			char y = it2->first;
			std::string temp;
			for(int i = 0; i < str.size(); i++){
				if(str[i] == x || str[i] == y)
					temp += str[i];
			}
			std::cout << x << "," << y << ":" << temp << std::endl;
			if(check(temp)){
				//std::cout << temp << std::endl;
				ans = std::max(ans, int(temp.size()));
			}
		}
	}

	return ans;
}

int main() {
	int n;
    std::string str;
    std::cin >> n;
    std::cin >> str;
    std::cout << calculate(n, str);
    return 0;
}
