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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root) {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            int selfDiameter = leftHeight + rightHeight;

            int leftDiameter = diameterOfBinaryTree(root->left);
            int rightDiameter = diameterOfBinaryTree(root->right);

            return max(selfDiameter, max(leftDiameter, rightDiameter));
        }
        return 0;
    }
    
    int height(TreeNode* root)
    {
        if (root) {
            return 1 + max(height(root->left), height(root->right));
        }
        return 0;
    }
    
};