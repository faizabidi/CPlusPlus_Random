#include <iostream>
#include <vector>
#include <list>

class Hashmap{
public:
	Hashmap(){
		buckets = 10;
		table.resize(buckets);
	}
	int hash(int key){
		return key % buckets;
	}
	void add(int key, int value){
		int index = hash(key);
		// Append it to that vector's list
		table[index].push_back(std::make_pair(key, value));
	}
	void print(){
		for(int i = 0; i < table.size(); i++){
			std::cout << "\nBucket " << i << std::endl;
			std::list<std::pair<int, int>> chain = table[i];
			for(auto it = chain.begin(); it != chain.end(); it++)
				std::cout << it->first << ":" << it->second << std::endl;;
		}
	}
	bool containsKey(int key){
		int index = hash(key);
		// Serach that list for the key
		std::list<std::pair<int, int>> chain = table[index];
		for(auto it = chain.begin(); it != chain.end(); it++){
			if(it->first == key)
				return true;
		}
		return false;
	}
private:
	int buckets;
	std::vector<std::list<std::pair<int, int>>> table;
};

int main(){
	Hashmap obj1;
	obj1.add(1,2);
	obj1.add(1,3);
	obj1.add(2,4);
	obj1.add(3,35);
	obj1.add(6,7);
	obj1.add(9,7);
	obj1.add(0,5);

	obj1.print();

	if(obj1.containsKey(0))
		std::cout << "\nKey 0 exists in the hashtable\n";

	return 0;
}
