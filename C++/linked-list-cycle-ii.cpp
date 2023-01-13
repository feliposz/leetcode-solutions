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
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode *> visited;
        
        for (ListNode *node = head; node; node = node->next) {
            if (find(visited.begin(), visited.end(), node) != visited.end()) {
                return node;
            }
            visited.push_back(node);
        }
        
        return nullptr;
    }
};