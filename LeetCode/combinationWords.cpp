#include <iostream>
#include <map>
#include <vector>

void permute(std::string str, int start, int end, std::map<std::string, bool> &hashmap){
	if(start == end){
		// if not in hashmap, add it
		if(hashmap.find(str) == hashmap.end())
			hashmap[str] = true;
	}
	for(int j = start; j <= end; j++){
		std::swap(str[start], str[j]);
		permute(str, start + 1, end, hashmap);
		std::swap(str[start], str[j]);
	}
}

void print(std::vector<std::string> array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

int main(){
	std::string str;
	std::cout << "Enter a word:";
	std::cin >> str;
	std::cout << "Combinations of that words are:\n";
	std::map<std::string, bool> hashmap;
	permute(str, 0, str.size() - 1, hashmap);
	std::map<std::string, bool>::iterator it;
	std::vector<std::string> ans;
	
	for(it = hashmap.begin(); it != hashmap.end(); it++)
		ans.push_back(it->first);

	std::sort(ans.begin(), ans.end());
	print(ans);

	return 0; 
}