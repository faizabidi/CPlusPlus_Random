// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_map>
#include <algorithm> 

class Solution{
public:
    bool check(std::string str, char ch){
    	for(int i = 0; i < str.length(); i++){
    		if(ch == str[i])
    			return false;
    	}
    	return true;
    }

    int lengthOfLongestSubstring(std::string s){
    	int max_substr_length = 0;
    	for(int i = 0; i < s.length(); i++){
    		std::string subStr;
    		int len_subStr = 0;
    		for(int j = i; j < s.length(); j++){
    			// If character not in subStr, add it to the string
    			if(check(subStr, s[j])){
    				subStr.push_back(s[j]);
    				len_subStr++;
    			}
    			else{
    				std::cout << subStr << std::endl;
    				break;
    			}
    		}
    		if(len_subStr > max_substr_length)
    			max_substr_length = len_subStr;
    	}
        return max_substr_length;
    }

    int lengthOfLongestSubstring2(std::string str){
    	int len = 0;
    	for(int i = 0; i < str.length(); i++){
    		bool check[256] = {false};
    		std::string subStr;
    		for(int j = i; j < str.length(); j++){
    			if(check[int(str[j])] == false){
    				check[int(str[j])] = true;
    				subStr.push_back(str[j]);
    			}
    			else
    				break;
    		}
    		if(len < subStr.length())
    			len = subStr.length();
    	}
    	return len;
    }

    // Using hashmap
    int lengthOfLongestSubstring3(std::string str){
        std::unordered_map<char, bool> hash;
        int len_max = 0;
        int len_string = str.size();
        for(int i = 0, j = 0; i < len_string && j < len_string;){
            // If character is not found in the hash table
            if(hash.find(str[j]) == hash.end()){
                std::cout << "Adding " << str[j] << " in the hash table." << std::endl;
                // Add it to the hash table
                hash[str[j]] = true;
                j++;
                // Store the size of the hashtable in len_max
                int hash_size = hash.size();
                len_max = std::max(len_max, hash_size);
            }
            // If character exists in the hash table
            // Implying a duplicate character
            else{
                std::cout << str[j] << " already exists in the hash table." << std::endl;
                // Remove the character stored at i
                hash.erase(str[i]);
                i++;
            }       
        }
        return len_max;
    }
};

int main(){
	Solution obj1;
	std::string str;

	std::cout << "Enter main string:";
	getline(std::cin, str);

	std::cout << obj1.lengthOfLongestSubstring3(str);
	return 0;
}