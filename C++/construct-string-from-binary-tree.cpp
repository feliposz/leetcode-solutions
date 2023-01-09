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
    string tree2str(TreeNode* root) {
        string s;
        if (root) {
            s += to_string(root->val);
            if (root->right) {
                s += "(" + tree2str(root->left) + ")";
                s += "(" + tree2str(root->right) + ")";
            } else if (root->left) {
                s += "(" + tree2str(root->left) + ")";
            }
        }
        return s;
    }
};