// https://leetcode.com/problems/sort-list/description/

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
    void printList(ListNode *node){
        if(!node)
            return;
        while(node){
            cout << node->val << "->";
            node = node->next;
        }
        cout << "NULL\n";
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *head = NULL, *temp = NULL;
        if(left->val <= right->val){
            head = left, temp = left;
            left = left->next;
        }
        else{
            head = right, temp = right;
            right = right->next;
        }
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if(left)
            temp->next = left;
        if(right)
            temp->next = right;
        return head;
    }
    
    ListNode* sortList(ListNode* head){
        if(!head || !head->next)
            return head;
        
        // Find the length of the list
        int length = 0;
        ListNode *temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }
        // Reset temp
        temp = head;
        // Store half of it in left and the other half in right
        // Create two lists and sort them
        ListNode *left = temp, *prev = NULL;
        int i = 0, mid = length / 2;
        // Left list
        while(i < mid){
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(prev)
            prev->next = NULL;
        // Right list
        ListNode  *right = temp;
        // Sort left list
        ListNode *sortedLeft = sortList(left);
        // Sort right list
        ListNode *sortedRight = sortList(right);
        // Merge them
        ListNode *sortedList = merge(sortedLeft, sortedRight);
        return sortedList;
    }
};
