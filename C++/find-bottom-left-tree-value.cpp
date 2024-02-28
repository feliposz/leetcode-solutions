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
    int depth_reached = -1;
    int leftmost = -1;
public:
    int findBottomLeftValue(TreeNode* root) {
        find(root, 0);
        return leftmost;
    }

    void find(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth > depth_reached) {
            leftmost = root->val;
            depth_reached = depth;
        }
        find(root->left, depth + 1);
        find(root->right, depth + 1);
    }
};