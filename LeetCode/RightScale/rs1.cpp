#include <iostream>
#include <vector>
#include <string>
#include <map>

int calculate(std::string str){
	std::map<char, int> hashmap;
	int count = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] != ','){
			if(hashmap.find(str[i]) == hashmap.end())
				hashmap[str[i]] = 1;
			else{
				count++;
				hashmap[str[i]]++;
			}
		}
	}
	return count;
}

long calculate2(std::string str){
	std::vector<char> array;
	long count = 0;
	for(long i = 0; i < str.size(); i++){
		if(str[i] != ',')
			array.push_back(str[i]);
	}
	std::map<char, long> hashmap;
	for(int i = 0; i < array.size(); i++){
		if(hashmap.find(array[i]) == hashmap.end())
			hashmap[array[i]] = 1;
		else
			count++;
	}
	return count;
}

int main(){
    std::string str;
    getline(std::cin, str);
    std::cout << calculate2(str);
    
    return 0;
}