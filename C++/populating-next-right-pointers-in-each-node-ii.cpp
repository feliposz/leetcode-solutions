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
        if (root) {
            queue<pair<Node*,int>> q;
            vector<vector<Node*>> layers;
            q.push({root, 0});

            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                Node* n = p.first;
                int level = p.second;

                if (level >= layers.size()) {
                    layers.resize(level+1);
                }
                layers[level].push_back(n);

                if (n->left) q.push({n->left, level+1});
                if (n->right) q.push({n->right, level+1});
            }

            for (auto &layer: layers) {
                int sz = layer.size();
                for (int i = 1; i < sz; i++) {
                    layer[i-1]->next = layer[i];
                }
            }
        }
        
        return root;
    }
};