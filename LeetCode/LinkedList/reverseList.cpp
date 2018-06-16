// https://leetcode.com/problems/reverse-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Iteratively
    // O(n) time & O(1) space
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL, *curr = head;
        while(curr != NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }
    // Recursively
    // O(n) time & O(n) space
    // https://stackoverflow.com/questions/354875/reversing-a-linked-list-in-java-recursively
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode *temp = head->next;
        head->next = NULL;
        ListNode *nextElem = reverseList(temp);
        temp->next = head;
        return nextElem;
    }
};