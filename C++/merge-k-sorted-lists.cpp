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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> data;
        
        vector<ListNode*> current = lists;
               
        for (;;) {

            int minIndex = -1;
            int minValue = INT32_MAX;

            for (int i = 0; i < current.size(); i++) {
                if (current[i]) {
                    if (current[i]->val < minValue) {
                        minValue = current[i]->val;
                        minIndex = i;
                    }
                }
            }
            
            if (minIndex == -1) {
                break;
            }
            
            current[minIndex] = current[minIndex]->next;            
            data.push_back(minValue);
        }
        
        
        ListNode *result = nullptr;
        
        while (!data.empty()) {
            result = new ListNode(data.back(), result);
            data.pop_back();
        }
        
        return result;
    }
};