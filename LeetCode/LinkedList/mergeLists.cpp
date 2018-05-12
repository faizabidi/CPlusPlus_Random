// https://leetcode.com/problems/merge-two-sorted-lists/discuss/125653/C++-without-extra-memory!

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && l2)
            return l2;
        if(l1 && !l2)
            return l1;
        if(!l1 && !l2)
            return NULL;
        ListNode *l3;
        // Find the head
        if(l1->val <= l2->val){
            l3 = l1;
            l1 = l1->next;
        }
        else{
            l3 = l2;
            l2 = l2->next;
        }
        ListNode *temp = l3;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        while(l1){
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2){
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        return l3;
    }
};
