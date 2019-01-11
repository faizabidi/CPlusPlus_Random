// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    int findLength(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    // O(n) time
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || !head->next || findLength(head) < k)
            return head;
        ListNode *prev = NULL, *curr = head, *nxt = NULL;
        int count = 0;
        while(curr && count < k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        if(curr && findLength(curr) >= k)
            head->next = reverseKGroup(curr, k);
        else if(curr)
            head->next = curr;
        return prev;
    }
};