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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (ListNode* n = head; n->next; n = n->next->next) {
            n->next = new ListNode(gcd(n->val, n->next->val), n->next);
        }
        return head;
    }

    int gcd(int x, int y) {
        int tmp;
        while (y) {
            tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
};