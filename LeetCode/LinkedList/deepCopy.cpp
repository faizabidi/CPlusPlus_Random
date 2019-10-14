// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// Time: 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// Time: O(n)
// Space: O(n)
class Solution {
private:
    Node *find(Node *head, Node *element){
        while(head){
            if(head == element)
                return head;
            head = head->next;
        }
        return NULL;
    }
public:
    Node *copyRandomList(Node* head){
        if(!head)
            return NULL;
        // Keep original copy of head
        Node *origHead = head;
        // Create a new list using original list's items
        // We'll take care of the random pointers later
        Node *newHead = new Node(head->val, head->next, head->random);
        Node *ans = newHead;
        // Hashmap to keep a map between head and newHead of the new list
        // We'll use this later to update the random pointers
        unordered_map<Node *, Node *> hashmap;
        hashmap[head] = newHead;
        head = head->next;
        while(head){
            Node *temp = new Node(head->val, head->next, head->random);
            newHead->next = temp;
            newHead = newHead->next;
            // Map it
            hashmap[head] = newHead;
            head = head->next;
        }
        // Now, go though the list again and fix all the random pointers
        // Reset newHead and head
        newHead = ans;
        head = origHead;
        // Find me a node in origHead whose address is newHead->random
        // Then use the hashmap where key = head address and value = newHead address
        while(head){
            Node *temp = find(origHead, newHead->random);
            // Find the corresponding newHead address for this head address
            auto it = hashmap.find(temp);
            if(it != hashmap.end())
                temp = hashmap[temp];
            // Make newHead->random point to the correct node
            newHead->random = temp;
            newHead = newHead->next;
            head = head->next;
        }
        return ans;
    }
};
