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
    int deepestLeavesSum(TreeNode* root) {
        int deepest = maxDepth(root);
        return leavesSum(root, deepest);
    }
    
    int maxDepth(TreeNode* root) {
        if (root) {
            int a = maxDepth(root->left);
            int b = maxDepth(root->right);
            return 1 + (a > b ? a : b);
        }
        return 0;
    }
    
    int leavesSum(TreeNode* root, int depth) {
        if (root) {
            int a = leavesSum(root->left, depth - 1);
            int b = leavesSum(root->right, depth - 1);
            return depth == 1 ? root->val : a + b;
        }
        return 0;
    }
};