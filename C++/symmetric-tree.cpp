/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> left;
    vector<int> right;
    
    bool isSymmetric(TreeNode* root) {
        visitLeft(root);
        visitRight(root);
        return left == right;
    }
    
    void visitLeft(TreeNode* node) {
        if (node) {
            left.push_back(node->val);
            visitLeft(node->left);
            visitLeft(node->right);
        } else {
            left.push_back(INT32_MIN);
        }
    }

    void visitRight(TreeNode* node) {
        if (node) {
            right.push_back(node->val);
            visitRight(node->right);
            visitRight(node->left);
        } else {
            right.push_back(INT32_MIN);
        }
    }

};