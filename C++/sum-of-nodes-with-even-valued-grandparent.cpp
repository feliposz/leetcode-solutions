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
    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparent(root, nullptr, nullptr);
    }
    
    int sumEvenGrandparent(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (root) {
            int result = 0;
            if (grandparent && (grandparent->val % 2 == 0)) {
                 result += root->val;
            }
            result += sumEvenGrandparent(root->left, root, parent);
            result += sumEvenGrandparent(root->right, root, parent);
            return result;
        }
        return 0;
    }
};