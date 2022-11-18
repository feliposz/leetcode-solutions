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
    int minDepth(TreeNode* root) {
        if (root) {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if (left && right) {
                return 1 + min(left, right);
            } else if (!left) {
                return 1 + right;
            } else if (!right) {
                return 1 + left;
            } else {
                return 0;
            }
        }
        return 0;
    }
};