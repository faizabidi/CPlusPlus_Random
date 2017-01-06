// https://www.hackerrank.com/challenges/30-dictionaries-and-maps

#include <iostream>
#include <unordered_map>

void input(std::unordered_map<std::string, long> &phone_book, int n){
	// Input the phone directory
	for(int i = 0; i < n; i++){
		std::string name;
		long number;
		
		std::cin.ignore();
		
		getline(std::cin, name);
		std::cin >> number;
		
		// Store in hash table	
		phone_book[name] = number;
	}

	// Input the names to be searched
	std::cout << "Enter names to be searched in the directory" << std::endl;
	std::string query;

	std::cin.ignore();
	while(getline(std::cin, query)){
    	if(phone_book[query])
			std::cout << query << "=" << phone_book[query] << std::endl;
		else
			std::cout << "Not found" << std::endl;
    }
}

int main() {
	int n;
	std::unordered_map<std::string, long> phone_book;
	std::vector<std::string> query;

	std::cout << "How many people? ";
	std::cin >> n;

    std::cout << "Enter name and phone number" << std::endl;
    input(phone_book, n);

    return 0;
}
