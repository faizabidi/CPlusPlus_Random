
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head)
            return head;
        ListNode *temp = head, *prev = head;
        while(temp->next){
            if(temp->val == temp->next->val)
                temp = temp->next;
            else{
                prev->next = temp->next;
                prev = temp->next;
                temp = prev;
            }
        }
        prev->next = temp->next;
        return head;
    }
};