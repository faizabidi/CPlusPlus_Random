// https://www.hackerrank.com/challenges/ctci-making-anagrams

#include <iostream>
#include <map>

int number_needed(std::string a, std::string b){
	// Store the first string in a hashtable
	std::map<char, int> hash;
	for(int i = 0; i < a.size(); i++)
		hash[a[i]]++;

	int common_characters = 0;
	
	// Iterate through the second string and subtract 
	// value in the dictionary
	for(int i = 0; i < b.size(); i++){
		// If present in hashtable
		if(hash.find(b[i]) != hash.end()){
			// If value if greater than 0
			if(hash[b[i]] > 0){
				common_characters++;
				hash[b[i]]--;
			}
		}
	}

	return (a.size() + b.size() - common_characters * 2);
}

int main(){
    std::string a;
    std::cin >> a;
    std::string b;
    std::cin >> b;
    
    std::cout << number_needed(a, b) << std::endl;

    return 0;
}
