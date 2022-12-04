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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> data;
        for (ListNode* node = head; node; node = node->next) {
            data[node->val]++;
        }
        ListNode* result = nullptr;
        for (auto it = data.rbegin(); it != data.rend(); it++) {
            if (it->second == 1) {
                result = new ListNode(it->first, result);
            }
        }
        return result;
    }
};