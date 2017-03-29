// https://leetcode.com/problems/palindrome-linked-list/#/description

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
    bool isPalindrome(ListNode* head){
        if(!head)
            return true;
        // Store everything in a string
        std::vector<int> array, orig_array;
        while(head){
            array.push_back(head->val);
            head = head->next;
        }
        for(int i = 0, j = array.size() - 1; i < j; i++, j--)
            if(array[i] != array[j])
                return false;
        return true;
    }
};