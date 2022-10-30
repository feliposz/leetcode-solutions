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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
    
    int sumRootToLeaf(TreeNode* root, int sum) {
        sum = sum * 2 + root->val;
        if ((root->left == nullptr) && (root->right == nullptr)) {
            return sum;
        }
        int l = root->left ? sumRootToLeaf(root->left, sum) : 0;
        int r = root->right ? sumRootToLeaf(root->right, sum) : 0;
        return l + r;
    }
};