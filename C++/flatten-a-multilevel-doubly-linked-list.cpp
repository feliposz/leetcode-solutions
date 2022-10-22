/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node *> stack;
        
        if (head) {
            for (Node* n = head; ; ) {
                if (n->child) {
                    if (n->next) {
                        stack.push_back(n->next);
                    }
                    n->child->prev = n;
                    n->next = n->child;
                    n->child = nullptr;
                }

                if (n->next) {
                    n = n->next;
                } else if (!stack.empty()) {
                    Node* other = stack.back();
                    stack.pop_back();
                    n->next = other;
                    other->prev = n;
                    n = other;
                } else {
                    break;
                }
            }
        }
        
        return head;
    }
};