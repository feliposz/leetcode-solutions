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
    int pairSum(ListNode* head) {
        vector<int> data;
        
        for (ListNode* node = head; node; node = node->next) {
            data.push_back(node->val);
        }
        
        int maxSum = INT32_MIN;
        int sz = data.size();
        
        for (int i = 0, j = sz - 1; i < j; i++, j--) {
            int sum = data[i] + data[j];
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
        
        return maxSum;
    }
};