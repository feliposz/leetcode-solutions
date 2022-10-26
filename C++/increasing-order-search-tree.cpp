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
    TreeNode* result = nullptr;
    
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        return result;
    }
    
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);
            result = new TreeNode(root->val, nullptr, result);
            traverse(root->left);
        }
    }
};