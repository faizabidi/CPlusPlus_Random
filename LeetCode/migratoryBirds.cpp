// https://www.hackerrank.com/challenges/migratory-birds

#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int calculate(int n, std::vector<int> array){
	// Create a sorted map
	std::map<int, int> map;
	for(int i = 0; i < array.size(); i++)
		map[array[i]]++;
	// Find the smallest value in the map
	std::map<int, int>::iterator it;
	int largest = INT_MIN;
	for(it = map.begin(); it != map.end(); it++){
		if(it->second > largest)
			largest = it->second;
	}
	// Find the first smallest in the map
	for(it = map.begin(); it != map.end(); it++){
		if(it->second == largest)
			return it->first;
	}
	return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> types(n);
    for(int types_i = 0; types_i < n; types_i++){
       cin >> types[types_i];
    }
    std::cout << calculate(n, types);
    return 0;
}
