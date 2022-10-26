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
    ListNode* sortList(ListNode* head) {

        if (head == nullptr) {
            return nullptr; // empty
        }
        
        if (head->next == nullptr) {
            return head; // 1 element, already sorted
        }
        
        // split in half
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
            } else {
                break;
            }
            slow = slow->next;
        }
        
        ListNode* a = head;
        ListNode* b = slow->next;
        
        slow->next = nullptr;
        
        // sort halves
        
        a = sortList(a);
        b = sortList(b);
        
        // merge
        
        ListNode* ans = merge(a, b);

        return ans;
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a && b) {
            if (a->val < b->val) {
                a->next = merge(a->next, b);
                return a;
            } else {
                b->next = merge(a, b->next);
                return b;
            }
        } else if (a) {
            return a;
        }
        return b;
    }
};