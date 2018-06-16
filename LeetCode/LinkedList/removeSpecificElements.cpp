// https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode* removeElements(ListNode* head, int val){
        if(!head)
            return head;
        ListNode *curr = head, *prev = head;
        while(curr){
            if(curr->val == val){
                // If it's the head node
                if(curr == head){
                    curr = curr->next;
                    prev = curr;
                    head = curr;
                }
                else{
                    curr = curr->next;
                    prev->next = curr;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};