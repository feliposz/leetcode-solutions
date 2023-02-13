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
    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            return pathSumFrom(root, targetSum) 
                + pathSum(root->left, targetSum) 
                + pathSum(root->right, targetSum);
        }
        return 0;
    }
    
    int pathSumFrom(TreeNode* root, long targetSum) {
        if (root) {
            return ((root->val == targetSum) ? 1 : 0)
                + pathSumFrom(root->left, targetSum - root->val) 
                + pathSumFrom(root->right, targetSum- root->val);
        }
        return 0;
    }
};