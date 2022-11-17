/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int level = 1;
        int count = 0;
        queue<Node *> q;
        
        if (root) {
            q.push(root);

            while (!q.empty()) {
                Node *n = q.front();
                q.pop();

                count++;
                if (count == level) {
                    count = 0;
                    level *= 2;
                } else if (!q.empty()) {
                    n->next = q.front();
                }

                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        
        return root;
    }
};