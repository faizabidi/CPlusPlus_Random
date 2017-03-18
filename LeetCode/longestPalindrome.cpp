#include <iostream>
#include <map>

int longest_Palindrome(std::string str){
	int result = 0;
	// Palindromes can be of even length or odd length
	// If it would be of even length then the number of characters in the
	// palindrome would also be even in count
	// For odd palindromes, we can at most have 1 single letter
	// Store everything in a hashmap
	std::map<char, int> hashmap;
	for(int i = 0; i < str.size(); i++){
		if(hashmap.find(str[i]) == hashmap.end())
			hashmap[str[i]] = 1;
		else
			hashmap[str[i]]++;
	}
	bool flag = false;
	std::map<char, int>::iterator it;
    for(it = hashmap.begin(); it != hashmap.end(); it++){
		std::cout << it->first << ":" << it->second << std::endl;
		int odd = 0;
		if(it->second % 2 == 0)
			result += it->second;
		else{
		    flag = true;
			result += it->second - 1;
		}
	}
	if(flag)
    	return result + 1;
    else
        return result;
}

int main(){
	std::string str;
	std::cout << "Enter a string:";
	getline(std::cin, str);

	std::cout << "Longest length palindrome that can be made from those letters = ";
	std::cout << longest_Palindrome(str);
	std::cout << std::endl;

	return 0;
}