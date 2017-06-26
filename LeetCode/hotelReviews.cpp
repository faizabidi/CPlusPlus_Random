#include <iostream>
#include <vector>
#include <map>
#include <sstream>

bool compare(std::pair<int,int> a, std::pair<int, int> b){
	// Print in descending order
	// If count is different
	if(a.second != b.second)
		return a.second > b.second;
	else
		return a.first > b.first;
}

void printMap(std::map<int, int> map){
	std::map<int, int>::iterator it;
	for(it = map.begin(); it != map.end(); it++)
		std::cout << it->first << ":" << it->second << std::endl;
}

void printVector(std::vector<std::string> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main(){
	std::string keywords;
	std::map<int, int> map;
	
	getline(std::cin, keywords);

	// Tokenize the input and store in a vector
	std::vector<std::string> tokens;
	std::stringstream ss(keywords);
	std::string buf; 
    while(ss >> buf)
        tokens.push_back(buf);

	int m;
	std::cin >> m;

	for(int i = 0; i < m; i++){
		int a;
		std::cin >> a;
		std::cin.ignore();

		int count = 0;

		std::string review;
		getline(std::cin, review);

		// Remove dots and commas and convert to lower case
		for(int i = 0; i < review.size(); i++){
			if(review[i] == '.' || review[i] == ',')
				review[i] = ' ';
			if(std::isupper(review[i]))
				review[i] = std::tolower(review[i]);
		}

		// Tokenize the input and store in a vector
		std::vector<std::string> tokens_review;
		std::stringstream ss(review);
		std::string buf; 

		while(ss >> buf)
        	tokens_review.push_back(buf);

    	// Compare the vectors and count the keywords found
    	for(int i = 0; i < tokens_review.size(); i++){
    		if(std::find(tokens.begin(), tokens.end(), tokens_review[i]) != tokens.end()){
    			count++;
    		}
    	}
    	// Store it in a hashmap
    	map[a] += count;
	}

	// Store it in a vector
	std::vector<std::pair<int, int>> ans;
	std::map<int, int>::iterator it;
	for(it = map.begin(); it != map.end(); it++){
		ans.push_back(std::make_pair(it->first, it->second));
	}

	// Sort it based on the second value in pair and then on the key
	std::sort(ans.begin(), ans.end(), compare);

	// Print the ans
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i].first << " ";
	}
	std::cout << std::endl;

    return 0;
}

/* Sample input
breakfast beach citycenter location metro view staff price
5
1
This hotel has a nice view of the citycenter. The location is perfect.
2
The breakfast is ok. Regarding location, it is quite far from citycenter but price is cheap so it is worth.
1
Location is excellent, 5 minutes from citycenter. There is also a metro station very close to the hotel.
1
They said I couldn't take my dog and there were other guests with dogs! That is not fair.
2
Very friendly staff and good cost-benefit ratio. Location is a bit far from citycenter.
*/