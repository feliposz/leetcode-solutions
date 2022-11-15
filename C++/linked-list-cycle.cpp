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
    bool hasCycle(ListNode *head) {
        set<ListNode *> visited;
        
        for (ListNode *node = head; node; node = node->next)
        {
            if (visited.count(node)) {
                return true;
            }
            visited.insert(node);
        }
        
        return false;
    }
};