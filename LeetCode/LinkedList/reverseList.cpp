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
    ListNode *reverseList_helper(ListNode *head, ListNode *prev){
        if(!head)
            return prev;
        ListNode *nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
        return reverseList_helper(head, prev);
    }
    // Recursive
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        return reverseList_helper(head, NULL);
    }
};