// https://www.hackerrank.com/challenges/pangrams
#include <vector>
#include <iostream>
#include <map>

std::string checkPangrams(std::string str){
	std::map<char, int> hashmap;
	
	// Store all characters in a hashmap
	for(int i = 0; i < str.size(); i++){
		// Don't store spaces
		if(str[i] != ' '){
			// Convert to lower case
			str[i] = char(std::tolower(str[i]));
			hashmap[str[i]]++;
		}
	}

	if(hashmap.size() == 26)
		return "pangram\n";
	else
		return "not pangram\n";
}

int main(){
	std::string str;
	getline(std::cin, str);

	std::cout << checkPangrams(str);

    return 0;
}
