// https://leetcode.com/problems/encode-and-decode-tinyurl/#/description

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

void printMap(std::map<std::string, std::string> map){
    std::map<std::string, std::string>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ":" << it->second << std::endl;
}

std::string convert2shorturl(std::string longurl, std::map<std::string, std::string> &map_urls, std::map<std::string, std::string> &map_codes){

	// Check if the longurl is not already in map_urls
	if(map_urls.find(longurl) == map_urls.end()){
		// Add it to map_urls
		// Create a 6 character code randomly choosing digits and letters
		// There are 62 characters in the database
		std::string database = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
		
		while(1){
			std::srand(time(NULL));
			std::string code;
			for(int i = 0; i < 6; i++){
				int index = std::rand() % 61;
				code += database[index];
			}
			// Check if this new code was generated in past too
			if(map_codes.find(code) == map_codes.end()){
				// Add code to the end of the tinyurl link
				std::string shorturl = "http://tinyurl.com/" + code;
				// Add to map_urls and map_codes
				map_urls[longurl] = shorturl;
				map_codes[code] = longurl;
				break;
			}
		}
	}
	return map_urls[longurl];
}

std::string convert2longurl(std::string shorturl, std::map<std::string, std::string> map_codes){

	// Code is the last 6 digits
	std::string code;
	for(int i = shorturl.size() - 6; i < shorturl.size(); i++)
		code.push_back(shorturl[i]);

	// Return the hashmap value
	return map_codes[code];
}

int main(){
	std::string longurl;
	std::cin >> longurl;

	// Hashmap to keep track of all the urls and codes
	std::map<std::string, std::string> map_urls, map_codes;

	// Keep track of list of codes generated
	std::vector<std::string> codes_list;
	
	std::string shorturl = convert2shorturl(longurl, map_urls, map_codes);
	std::cout << shorturl << std::endl;
	
	std::string original_url = convert2longurl(shorturl, map_codes);
	std::cout << original_url << std::endl;

	return 0;
}
