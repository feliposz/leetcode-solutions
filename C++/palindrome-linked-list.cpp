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
    bool isPalindrome(ListNode* head) {
        ListNode* rev = reverse(head);
        ListNode* a = head, *b = rev;
        for (; a && b; a = a->next, b = b->next)
        {
            if (a->val != b->val) {
                return false;
            }
        }
        
        return a == b;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* result = nullptr;
        
        for (ListNode* n = head; n; n = n->next)
        {
            ListNode* node = new ListNode(n->val, result);
            result = node;
        }
        
        return result;
    }
};