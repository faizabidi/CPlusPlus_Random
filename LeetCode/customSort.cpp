#include <iostream>
#include <vector>
#include <map>

bool compare(const std::pair<int, int> a, const std::pair<int, int> b){
    // If frequency is same
    if(a.second == b.second)
    	return a.first < b.first;
    return a.second < b.second;
}

std::vector<std::pair<int, int> > customSort(std::vector <int> array){

	// Store all numbers in a map
	std::map<int, int> hashmap;
	for(int i = 0; i < array.size(); i++)
		hashmap[array[i]]++;

	// Create another vector to store key and value
	std::vector<std::pair<int, int> > ans;
	std::map<int, int>::iterator it;
	for(it = hashmap.begin(); it != hashmap.end(); it++){
		int frequency = it->second;
		while(frequency > 0){
			ans.push_back(std::make_pair(it->first, it->second));
			frequency--;
		}
	}
	std::sort(ans.begin(), ans.end(), compare);

	return ans;
}

// Print vector, each element on a new line
void printArray(std::vector<std::pair<int, int> > array){
	for(int i = 0; i < array.size(); i++)
		std::cout << array[i].first << ":" << array[i].second << std::endl;
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for(int i = 0; i < n; i++)
		std::cin >> array[i];

	std::vector<std::pair<int, int> > ans = customSort(array);

	printArray(ans);

	return 0;
}

