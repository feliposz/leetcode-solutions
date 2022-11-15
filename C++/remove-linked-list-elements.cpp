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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = nullptr;
        if (head) {
            if (head->val != val) {
                result = head;
                result->next = removeElements(head->next, val);
            } else {
                result = removeElements(head->next, val);
            }
        }
        return result;
    }
};