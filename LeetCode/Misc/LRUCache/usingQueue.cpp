class LRUCache{
public:
    LRUCache(int capacity){
        maxSize = capacity;
    }
    
    int get(int key){
        auto it = cache.find(key);
        if(it == cache.end())
            return -1;
        else{
            helper(q, key);
            return cache[key];
        }
    }
    
    void put(int key, int value){   
        auto it = cache.find(key);
        if(it == cache.end()){
            if(cache.size() == maxSize){
                cache.erase(q.front());
                q.pop();
                cache[key] = value;
                q.push(key);
            }
            else{
                cache[key] = value;
                q.push(key);
            }
        }
        else{
            cache[key] = value;
            helper(q, key);
        }
    }
private:
    int maxSize;
    map<int, int> cache;
    queue<int> q;
    void helper(queue<int> &q, int key){
        queue<int> temp;
        while(!q.empty()){
            if(q.front() != key)
                temp.push(q.front());
            q.pop();
        }
        q = temp;
        q.push(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */