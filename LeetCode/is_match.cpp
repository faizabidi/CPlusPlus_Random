#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

bool is_match(std::string pattern, std::vector<std::string> input){
	std::map<char, std::string> hash;
	std::map<char, std::string>::iterator it;
	for(int i = 0; i < pattern.size(); i++){
		// If key doesn't exists, add it to the hashmap
		if(hash.find(pattern[i]) == hash.end()){
			// Check if value being added is already in the hashmap
			for(it = hash.begin(); it != hash.end(); it++){
				if(it->second == input[i])
					return false;
			}
			// Else, add it to the hashmap
			hash[pattern[i]] = input[i];
		}
		else{
			// If already in hashmamp
			// Check if the new value matches with the old one
			if(hash[pattern[i]] != input[i])
				return false;
		}
	}	
	return true;
}

int main(){
	std::string pattern;
	std::string input;
	std::vector<std::string> tokens;

	std::cout << "Enter the pattern:";
	std::cin >> pattern;
	std::cin.ignore();

	std::cout << "Enter the input:";
	getline(std::cin, input);
	std::stringstream ss(input);
    std::string buf; 

    // Tokenize the input and store in a vector
    while(ss >> buf)
        tokens.push_back(buf);

	if(is_match(pattern, tokens))
		std::cout << "True\n";
	else
		std::cout << "False\n";

	return 0;
}