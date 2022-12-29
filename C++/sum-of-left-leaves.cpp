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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root) {            
            if (root->left) {
                if (root->left->left == nullptr && root->left->right == nullptr) {
                    result += root->left->val;
                } else {
                    result += sumOfLeftLeaves(root->left);
                }
            }            
            result += sumOfLeftLeaves(root->right);
        }
        return result;
    }
};