// https://leetcode.com/problems/lru-cache/description/
// https://leetcode.com/problems/lru-cache/discuss/46143/72ms-C++-solution-using-hashtable-and-double-linked-list.

// O(1) time
class LRUCache{
private:
    // Structure for doubly linklist
    // 1=2=3=4=5
    // Head......TAIL
    // FRONT.....END
    struct Node{
        int key, val;
        Node *next, *prev;
    };
    Node *head, *tail;
    // Maximum number of cache pages
    int maxPages;
    // Keep a track of how many pages filled
    int size;
    // Hashmap to store cache and refereces to the Node
    map<int, Node*> cache;
    // Create a new node of struct Node type
    Node *createNode(int key, int value){
        Node *newNode = new Node;
        newNode->key = key, newNode->val = value;
        newNode->next = NULL, newNode->prev = NULL;
        return newNode;
    }
     // Add a node to the end (right most) of the DLL
    void addNode(Node *givenNode){
        // If this is the first node being added
        if(!head || !tail){
            cout << "Added " << givenNode->key << " as the head and tail of the DLL.\n";
            head = givenNode;
            tail = givenNode;
            // One page added to the cache
            size++;
            // Add it to the cache as well
            cache[givenNode->key] = givenNode;
            return;
        }
        givenNode->prev = tail;
        givenNode->next = tail->next;
        tail->next = givenNode;
        tail = givenNode;
        cout << "Added " << givenNode->key << " to the end of the DLL.\n";
        // One page added to the cache
        size++;
        // Add it to the cache as well
        cache[givenNode->key] = givenNode;
    }
    // Delete head (left most) node
    void deleteHead(Node *givenNode){
        // One page deleted from the cache
        size--;
        // Delete from cache as well
        cache.erase(givenNode->key);
        Node *newNode = givenNode->next;
        head = newNode;
        delete givenNode;
        cout << "Deleted " << givenNode->key << " from the DLL.\n";
    }
    // Move some node to the tail
    void moveKeyToTail(Node *givenNode){
        // If givenNode is the tail node
        if(givenNode == tail)
            return;
        // If givenNode is the head node
        if(givenNode == head){
            cout << givenNode->key << " is the head. Moving it to being a tail.\n";
            Node *newNode = head;
            head = head->next;
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            return;
        }
        // Else, move it to the end
        givenNode->prev->next = givenNode->next;
        givenNode->next->prev = givenNode->prev;
        givenNode->next = tail->next;
        givenNode->prev = tail;
        tail->next = givenNode;
        tail = givenNode;
        cout << givenNode->key << " moved to the tail of the DLL.\n";
    }
public:
    // Default constructor
    LRUCache(int capacity) {
        maxPages = capacity;
        size = 0;
        head = NULL, tail = NULL;
    }
    // Get page from the cache
    int get(int key){
        auto it = cache.find(key);
        // If not in the cache
        if(it == cache.end()){
            cout << key << " is not in the cache.\n";
            return -1;
        }
        // Else, return the key's value and move this node of the DLL to the end
        moveKeyToTail(it->second);
        cout << "Running it->second in the get function = " << it->second->val << endl;
        return it->second->val;
    }
    // Put pages into cache
    void put(int key, int value){
        cout << "Size = " << size << endl;
        // If this key already exists in the cache, update its value and move to the end of the DLL
        auto it = cache.find(key);
        if(it != cache.end()){
            cout << key << " already exists in the cache.\n";
            it->second->val = value;
            moveKeyToTail(it->second);
            return;
        }
        // Create a new node
        Node *newNode = createNode(key, value);
        // If no space left in the cache
        if(size >= maxPages){
            cout << "Cache full. Have to delete " << head->key << " from the DLL.\n";
            deleteHead(head);
        }
        // Add this to the end of the DLL
        addNode(newNode);
    }
};