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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> data;
        
        traverse(root, data);
        
        return buildBST(data, 0, data.size() - 1);
    }
    
    void traverse(TreeNode* root, vector<int> &data) {
        if (root) {
            traverse(root->left, data);
            data.push_back(root->val);
            traverse(root->right, data);
        }
    }
    
    TreeNode* buildBST(vector<int> &data, int i, int j) {
        TreeNode* result = nullptr;
        if (i <= j) {
            int mid = (i + j) / 2;
            result = new TreeNode(data[mid], 
                                 buildBST(data, i, mid-1),
                                 buildBST(data, mid+1, j));
        }
        return result;
    }
};