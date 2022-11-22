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
    bool findTarget(TreeNode* root, int k) {
        return findTarget(root, root, k);
    }
    
    bool findTarget(TreeNode* root, TreeNode* node, int k) {
        if (node) {
            int other = k - node->val;
            if (other != node->val && exists(root, other)) {
                return true;
            }
            return findTarget(root, node->left, k) || findTarget(root, node->right, k);
        }
        return false;
    }
    
    bool exists(TreeNode* node, int val) {
        while (node) {
            if (val < node->val) {
                node = node->left;
            } else if (val > node->val) {
                node = node->right;
            } else {
                return true;
            }
        }
        return false;
    }
};