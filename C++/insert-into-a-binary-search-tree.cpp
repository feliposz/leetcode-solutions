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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root) {
            TreeNode* node = root;
            while (true) {
                if (val < node->val) {
                    if (node->left) {
                        node = node->left;
                    } else {
                        node->left = new TreeNode(val);
                        break;
                    }
                } else {
                    if (node->right) {
                        node = node->right;
                    } else {
                        node->right = new TreeNode(val);
                        break;
                    }
                }
            }
        } else {
            root = new TreeNode(val);
        }
        return root;
    }
};