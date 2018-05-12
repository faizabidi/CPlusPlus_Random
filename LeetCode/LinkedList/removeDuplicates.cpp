
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode* deleteDuplicates(ListNode* head){
        if(!head)
            return NULL;
        ListNode *temp = head;
        while(temp){
            ListNode *same = temp;
            while(same->next && same->val == same->next->val)
                same = same->next;
            temp->next = same->next;
            temp = temp->next;
        }
        return head;
    }
};