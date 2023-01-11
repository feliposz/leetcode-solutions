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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        bool l1 = false;
        bool l2 = false;
        
        if (list1 && list2) {
            if (list1->val < list2->val) {
                l1 = true;
            } else {
                l2 = true;
            }
        } else if (list1) {
            l1 = true;   
        } else if (list2) {
            l2 = true;
        }

        ListNode *result = nullptr;

        if (l1) {
            result = new ListNode(list1->val, mergeTwoLists(list1->next, list2));
        } else if (l2) {
            result = new ListNode(list2->val, mergeTwoLists(list1, list2->next));
        }
        
        return result;
    }
};