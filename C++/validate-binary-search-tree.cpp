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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT32_MIN, INT32_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max) {
        if (root) {
            if ((root->val >= min) && (root->val <= max)) {
                return isValidBST(root->left, min, (long)root->val - 1) && 
                    isValidBST(root->right, (long)root->val + 1, max);
            } else {
                return false;
            }
        }
        return true;
    }
};