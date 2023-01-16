/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            return p;
        } else if (root == q) {
            return q;
        } else if (root) {
            TreeNode* a = lowestCommonAncestor(root->left, p, q);
            TreeNode* b = lowestCommonAncestor(root->right, p, q);
            if (((a == p) && (b == q)) || ((a == q) && (b == p))) {
                return root;
            }
            return a ? a : b;
        } else {
            return nullptr;
        }
    }
};