#include <iostream>
#include <map>
#include <vector>

void print(std::vector<std::string> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

bool check(std::string pattern, std::string str){
	std::map<char, std::string> hashmap;

	// Vector to store all the sub-strings of the main string
	std::vector<std::string> array;
	std::string temp;
	for(int i = 0; i < str.size(); i++){
		if(str[i] != ' ')
			temp += str[i];
		else{
			array.push_back(temp);
			// Clear the temp to store the next sub-string
			temp.clear();
		}
	}
	array.push_back(temp);

	if(pattern.size() != array.size())
		return false;

	for(int i = 0; i < array.size(); i++){
		// If not in hashmap, check and add it if needed
		if(hashmap.find(pattern[i]) == hashmap.end()){
			// Search if array[i] is already some key's value in the hashmap
			// If so, return false
			std::map<char, std::string>::iterator it;
			for(it = hashmap.begin(); it != hashmap.end(); it++){
				if(array[i] == it->second)
					return false;
			}
			hashmap[pattern[i]] = array[i];
		}
		else{
			if(hashmap[pattern[i]] != array[i])
				return false;
		}
	}
	return true;
}

int main(){
	std::string pattern, str;

	std::cout << "Enter a pattern:";
	std::cin >> pattern;
	std::cin.ignore();

	std::cout << "Enter the string:";
	getline(std::cin, str);

	if(check(pattern, str))
		std::cout << "True\n";
	else
		std::cout << "False\n";

	return 0;
}