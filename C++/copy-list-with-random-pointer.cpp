/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;
    
    Node* copyRandomList(Node* head) {
        Node* ans = copyNodes(head);
        fillRandom(head, ans);
        return ans;
    }
    
    Node* copyNodes(Node* head) {
        if (head) {
            Node* node = new Node(head->val, copyNodes(head->next), nullptr);
            nodeMap[head] = node;
            return node;
        }
        return nullptr;
    }
    
    void fillRandom(Node* src, Node* dst) {
        while (src) {
            if (src->random) {
                dst->random = nodeMap[src->random];
            }
            src = src->next;
            dst = dst->next;
        }
    }
};