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
    ListNode* deleteMiddle(ListNode* head) {
        int sz = 0;
        for (ListNode* n = head; n; n = n->next) {
            sz++;
        }
        
        if (sz < 2) {
            return nullptr;
        }
        
        int mid = sz / 2;
        int i = 0;
        for (ListNode* n = head; n; n = n->next) {
            if (i++ == mid - 1) {
                n->next = n->next->next;
            }
        }
        
        return head;
    }
};