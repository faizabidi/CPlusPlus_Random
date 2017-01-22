// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head){
        // Empty list
        if(head == NULL)
            return NULL;
        ListNode *temp = head;
        while(temp->next != NULL){
            std::swap(temp->val, temp->next->val);
            temp = temp->next->next;
            if(temp == NULL)
                return head;
        }
        return head;
    }
};