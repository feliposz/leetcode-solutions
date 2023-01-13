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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        for (ListNode* n = head; n; n = n->next) {
            size++;
        }
        int middle = size / 2;
        int pos = 0;
        ListNode* n = head;
        for (; n && (pos < middle); n = n->next) {
            pos++;
        }        
        return n;
    }
};