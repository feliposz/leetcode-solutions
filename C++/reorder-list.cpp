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
    void reorderList(ListNode* head) {
        vector<ListNode*> tmp;
        
        for (ListNode* n = head; n; n = n->next) {
            tmp.push_back(n);
        }
        
        int i = 0, j = tmp.size() - 1;
        
        while (true) {
            if (i < j) {
                tmp[i]->next = tmp[j];
            } else {
                tmp[i]->next = nullptr;
                break;
            }
            i++;
            if (i < j) {
                tmp[j]->next = tmp[i];
            } else {
                tmp[j]->next = nullptr;
                break;
            }
            j--;
        }
    }
};