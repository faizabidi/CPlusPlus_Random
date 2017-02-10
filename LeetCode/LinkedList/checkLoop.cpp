// https://www.hackerrank.com/challenges/ctci-linked-list-cycle

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if(!head)
      return 0;
    Node* slow = head;
    Node* fast = head;
    while(slow && fast){
        slow = slow->next;
        if(slow->next)
            fast = fast->next->next;
        else
            return 0;
        if(slow == fast)
            return 1;
    }
    return 0;
}
