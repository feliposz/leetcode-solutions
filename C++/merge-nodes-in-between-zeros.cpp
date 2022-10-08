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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* current = new ListNode();
        ListNode* result = current;
        
        for (ListNode* node = head->next; node; node = node->next)
        {
            current->val += node->val;
            if ((node->val == 0) && (node->next)) {
                current->next = new ListNode();
                current = current->next;
            }
        }
        
        return result;
    }
};