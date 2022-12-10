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
        if (root) {
            TreeNode* l = lowestCommonAncestor(root->left, p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);

            if (((l == p) && (r == q)) || ((l == q) && (r == p))) {
                return root;
            }
            if (root == p) {
                return root;
            }
            if (root == q) {
                return root;
            }
            
            return l ? l : r;
        }
        return nullptr;
    }
};