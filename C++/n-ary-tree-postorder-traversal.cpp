/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> list;
        traverse(root, list);
        return list;
    }
    
    void traverse(Node* root, vector<int> &list) {
        if (root) {
            for (Node *node: root->children) {
                traverse(node, list);
            }
            list.push_back(root->val);
        }
    }
};