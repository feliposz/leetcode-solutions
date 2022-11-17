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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* node = nullptr;
        
        if (root1 && root2) {
            node = new TreeNode(root1->val + root2->val, 
                               mergeTrees(root1->left, root2->left),
                               mergeTrees(root1->right, root2->right));
        } else if (root1) {
            node = new TreeNode(root1->val,
                               mergeTrees(root1->left, nullptr),
                               mergeTrees(root1->right, nullptr));
            
        } else if (root2) {
            node = new TreeNode(root2->val,
                               mergeTrees(nullptr, root2->left),
                               mergeTrees(nullptr, root2->right));
            
        }
        
        return node;
    }
};