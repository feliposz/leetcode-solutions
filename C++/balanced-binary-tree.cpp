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
    bool result;
    
    bool isBalanced(TreeNode* root) {
        result = true;
        checkDepth(root, 0);
        return result;
    }
    
    int checkDepth(TreeNode* root, int depth) {
        if (root) {
            int a = checkDepth(root->left, depth + 1);
            int b = checkDepth(root->right, depth + 1);
            if (abs(a - b) < 2) {
                return max(a, b);
            } else {
                result = false;
                return depth;
            }
        }
        else {
            return depth;
        }
    }
};