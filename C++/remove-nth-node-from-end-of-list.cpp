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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = countNodes(head);
        int target = count - n;

        if (target <= 0) {
            return head->next;
        }

        ListNode* node = head;

        for (int i = 0; i < target - 1; i++) {
            node = node->next;
        }
        
        node->next = node->next->next;
        
        return head;        
    }
    
    int countNodes(ListNode* node) {
        int count = 0;
        for (; node; node = node->next) {
            count++;
        }
        return count;
    }
};