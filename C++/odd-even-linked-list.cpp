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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }        
        
        ListNode* ans = head;
        ListNode* odd = head;
        ListNode* firstEven = head->next;
        ListNode* even = head->next;
        
        int i = 1;
        for (ListNode* p = head; p;) {
            ListNode* next = p->next;
            if (i % 2) {
                odd->next = p;
                odd = odd->next;
                odd->next = nullptr;
            } else {
                even->next = p;
                even = even->next;
                even->next = nullptr;
            }
            i++;
            p = next;
        }
        
        odd->next = firstEven;
        
        return ans;        
    }
};