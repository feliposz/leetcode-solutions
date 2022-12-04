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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode *a = headA; a; a = a->next) {
            for (ListNode *b = headB; b; b = b->next) {
                if (a == b) {
                    return a;
                }
            }
        }     
        return nullptr;
    }
};