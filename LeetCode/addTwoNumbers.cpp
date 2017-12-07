// https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    std::string sum(std::string sum1, std::string sum2){

        std::string ans = "";
        int size1 = sum1.size();
        int size2 = sum2.size();
        int i = 0, carry = 0;
        while(i < size1 && i < size2){
            std::string temp = std::to_string((sum1[i] - '0') + (sum2[i] - '0') + carry);
            if(temp.size() > 1){
                ans += temp[1];
                carry = temp[0] - '0';
            }
            else{
                ans += temp[0];
                carry = 0;
            }
            i++;
        }
        // Add any remaining digits left
        for(int j = i; j < sum1.size(); j++){
            std::string temp = std::to_string((sum1[j] - '0') + carry);
            if(temp.size() > 1){
                ans += temp[1];
                carry = temp[0] - '0';
            }
            else{
                ans += temp[0];
                carry = 0;
            }
        }
        for(int j = i; j < sum2.size(); j++){
            std::string temp = std::to_string((sum2[j] - '0') + carry);
            if(temp.size() > 1){
                ans += temp[1];
                carry = temp[0] - '0';
            }
            else{
                ans += temp[0];
                carry = 0;
            }
        }
        // If any carry still left, add that too
        if(carry != 0)
            ans += std::to_string(carry);
        return ans;
    }
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        // Edge cases
        if(!l1 && l2)
            return l2;
        if(l1 && !l2)
            return l1;
        if(!l1 && !l2)
            return NULL;
        
        // Iterate through both the list first and find the sum
        std::string sum1, sum2;
        
        while(l1 != NULL){
            sum1 += std::to_string(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            sum2 += std::to_string(l2->val);
            l2 = l2->next;
        }
        std::string sumTotal = sum(sum1, sum2);
        
        ListNode *ans = new ListNode(sumTotal[0] - '0');
        ListNode *temp = ans;
        //Now store this string one by one in a linkedlist
        for(int i = 1; i < sumTotal.size(); i++){
            // Create a node with this value
            ListNode *newNode = new ListNode(sumTotal[i] - '0');
            temp->next = newNode;
            temp = newNode;
        }

        return ans;
    }
};