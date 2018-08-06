// https://leetcode.com/problems/lru-cache/description/
// O(n) time complexity for get and put functions. Can we do better?

class LRUCache{
public:
    LRUCache(int capacity){
        maxSize = capacity;
        currSize = 0;
    }
    void printAges(map<int, int> hashmapOfAge){
        for(auto it = hashmapOfAge.begin(); it != hashmapOfAge.end(); it++)
            cout << "Age of " << it->first << " = " << it->second << endl;
    }
    void readjustAges(int key){
        // Add 1 to all the keys in the hashmap
        for(auto it = ageOfKeys.begin(); it != ageOfKeys.end(); it++)
            it->second += 1;
        // Add the new key to ageOfKeys
        ageOfKeys[key] = 0;
    }
    int findOldest(map<int, int> hashmapOfAge){
        int oldestKey = 0, value = INT_MIN;
        for(auto it = hashmapOfAge.begin(); it != hashmapOfAge.end(); it++){
            if(it->second > value){
                value = it->second;
                oldestKey = it->first;
            }
        }
        return oldestKey;
    }
    // Access the cache
    // O()
    int get(int key){
        auto it = cache.find(key);
        int value = 0;
        if(it == cache.end()){
            //cout << key << " is not in the cache.\n";
            return -1;
        }
        else{
            //cout << key << " got accessed.\n";
            value = cache[key];
            // Readjust the age of this key
            ageOfKeys[key] = 0;
        }
        // Readjust the ages
        readjustAges(key);
        // Print all ages
        //printAges(ageOfKeys);
        
        return value;
    }
    // Add to the cache
    void put(int key, int value){
        // If inserting an element that's already in the cache
        auto it = cache.find(key);
        if(it != cache.end())
            cache[key] = value;
        else{
            if(currSize < maxSize){
                //cout << "Cache not full. Adding " << key << " to cache.\n";
                cache[key] = value;
                currSize++;
            }
            // Else, remove the least used element
            else{
                int leastUsedKey = findOldest(ageOfKeys);
                //cout << "Cache full. Removing " << leastUsedKey << " from cache and adding " << key << endl;
                // Remove from cache
                auto it = cache.find(leastUsedKey);
                if(it != cache.end())
                    cache.erase(it);
                // Remove from ageOfKeys as well
                auto it1 = ageOfKeys.find(leastUsedKey);
                if(it1 != ageOfKeys.end())
                    ageOfKeys.erase(it1);
                // Add the new key
                cache[key] = value;
            }
        }
        // Readjust the ages
        readjustAges(key);
        // Print all ages
        //printAges(ageOfKeys);
    }
private:
    map<int, int> cache;
    int maxSize, currSize;
    map<int, int> ageOfKeys;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */