// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        // If list 1 is empty
        if(l1 == NULL && l2 != NULL)
            return l2;
        // If list 2 is empty
        if(l1 != NULL && l2 == NULL)
            return l1;
        // If both lists are empty
        if(l1 == NULL && l2 == NULL)
            return l1;
        // If both lists are not empty
        ListNode *temp, *start;
        if(l1->val < l2->val){
            temp = new ListNode(l1->val);
            start = temp;
            l1 = l1->next;
        }
        else{
            temp = new ListNode(l2->val);
            start = temp;
            l2 = l2->next;
        }
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        // Check if more items left in the two lists
        if(l1)
            temp->next = l1;
        else if(l2)
            temp->next = l2;
        return start;
    }
};