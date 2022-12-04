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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*> tmp;
        
        if (!head) {
            return nullptr;
        }
        
        for (ListNode* node = head; node; node = node->next) {
            tmp.push_back(node);
        }
        
        int sz = tmp.size();
        
        for (int i = 1; i < sz; i += 2) {
            swap(tmp[i-1], tmp[i]);
        }
        
        for (int i = 0; i < sz; i ++) {
            
            if (i == sz - 1) {
                tmp[i]->next = nullptr;
            } else {
                tmp[i]->next = tmp[i+1];
            }            
        }
        
        return tmp[0];
    }
};