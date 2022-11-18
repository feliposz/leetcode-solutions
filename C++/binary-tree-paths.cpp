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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        binaryTreePaths(root, "", ans);
        return ans;
    }
    
    void binaryTreePaths(TreeNode* root, string s, vector<string> &ans) {
        if (root) {
            string t;
            if (s.size()) {
                t = s + "->" + to_string(root->val);
            } else {
                t = to_string(root->val);
            }
            if (!root->left && !root->right) {
                ans.push_back(t);
            } else {
                binaryTreePaths(root->left, t, ans);
                binaryTreePaths(root->right, t, ans);
            }            
        }
    }
};