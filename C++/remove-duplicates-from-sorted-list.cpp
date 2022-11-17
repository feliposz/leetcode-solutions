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
    ListNode* deleteDuplicates(ListNode* head) {
        
        for (ListNode* n = head; n; n = n->next) {
            while ((n->next) && (n->val == n->next->val)) {
                n->next = n->next->next;
            }
        }        
        
        return head;
    }
};