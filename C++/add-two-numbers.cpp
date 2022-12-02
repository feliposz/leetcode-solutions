/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digits;
        int val = 0;
        int carry = 0;
        
        while (l1 || l2) {
            val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = val / 10;
            val = val % 10;
            
            digits.push_back(val);
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        if (carry) {
            digits.push_back(carry);
        }
        
        ListNode *result = nullptr;
        
        while (digits.size() > 0) {
            result = new ListNode(digits.back(), result);
            digits.pop_back();
        }
        
        return result;
    }
};