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
    vector<int> rightSide;
        
    vector<int> rightSideView(TreeNode* root) {
        visit(root, 0);
        return rightSide;
    }
    
    void visit(TreeNode* root, int level) {
        if (root) {
            if (rightSide.size() <= level) {
                rightSide.resize(level+1);                
            }
            rightSide[level] = root->val;
            visit(root->left, level+1);
            visit(root->right, level+1);
        }
    }
};