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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root) {
            if (equalTree(root, subRoot)) {
                return true;
            }
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return false;
    }
    
    bool equalTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        } else if (a && b && a->val == b->val) {
            return equalTree(a->left, b->left) && equalTree(a->right, b->right);
        } else {
            return false;
        }
    }
};