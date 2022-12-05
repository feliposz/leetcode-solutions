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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> tmp;
        
        for (ListNode* n = head; n; n = n->next) {
            tmp.push_back(n);
        }
        
        int sz = tmp.size();
        
        for (int i = 0, j = i + k; j <= sz; i = j, j += k) {
            reverse(tmp.begin() + i, tmp.begin() + j);
        }
        
        for (int i = 1; i < sz; i++) {
            tmp[i-1]->next = tmp[i];
        }
        tmp.back()->next = nullptr;
        
        return tmp[0];
    }
};