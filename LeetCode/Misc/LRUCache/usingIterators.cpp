// https://leetcode.com/problems/lru-cache/description/

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


// O(1) get and put time complexity
class LRUCache{
private:
	// Map to store keys and a list of iterators for the DLL
	map<int, list<pair<int, int>>::iterator> cache;
	// Max capacity of the cache
	int maxCachePages;
	// Check the size of cache on each insertion
	int currSize;
	// List to maintain the key, value pairs
	list<pair<int, int>> dllCache;
public:
	LRUCache(int capacity){
		maxCachePages = capacity;
		currSize = 0;
	}
	// Access cache
	int get(int key){
		// Check if it exists in the cache
		auto it = cache.find(key);
		if(it == cache.end())
			return -1;
		// Else, print the value and move this node to the right end of the DLL
		// It can also be called the "front" of the DLL
		// Delete the node from its existing position and move it to the front
		dllCache.erase(cache[key]);
		dllCache.push_front(make_pair(key, cache[key]->second));
		// Update cache to point to the new address
		cache[key] = dllCache.begin();
		return dllCache.front().second;
	}
	// Insert pages into cache
	void put(int key, int value){
		// Check if key already exists in the cache
		auto it = cache.find(key);
		if(it != cache.end()){
			// Move it to the front of the DLL and update its value
			dllCache.erase(cache[key]);
			dllCache.push_front(make_pair(key, value));
			cache[key] = dllCache.begin();
			return;
		}
		// If cache is full
		if(currSize >= maxCachePages){
			cout << "Cache full. Removing " << dllCache.back().first << " from the cache.\n";
			cache.erase(dllCache.back().first);
			// Delete the tail node
			dllCache.pop_back();
			// Add the new value to the end of the DLL
			dllCache.push_front(make_pair(key, value));
			// Add the key to the cache
			cache[key] = dllCache.begin();
		}
		// If cache is not full
		else{
			cout << "Cache is not full with size = " << currSize << endl;
			// Add the new value to the end of the DLL
			dllCache.push_front(make_pair(key, value));
			// Add the key to the cache
			// begin = front in DLL
			cache[key] = dllCache.begin();
			currSize++;
		}
	}
};

int main(){
	LRUCache obj1(2);
	obj1.put(1,1);
	obj1.put(2,2);
	cout << obj1.get(1) << endl;
	obj1.put(3,3);
	cout << obj1.get(2) << endl;
	obj1.put(4,4);
	cout << obj1.get(1) << endl;
	cout << obj1.get(3) << endl;
	cout << obj1.get(4) << endl;

	return 0;
}
