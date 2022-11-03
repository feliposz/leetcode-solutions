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
    TreeNode* root;
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        root = nullptr;
        for (int n: preorder) {
            if (root) {
                TreeNode* node = root;
                while (true) {
                    if (n < node->val) {
                        if (node->left) {
                            node = node->left;
                        } else {
                            node->left = new TreeNode(n);
                            break;
                        }                        
                    } else {
                        if (node->right) {
                            node = node->right;
                        } else {
                            node->right = new TreeNode(n);
                            break;
                        }                        
                    }
                }
            } else {
                root = new TreeNode(n);
            }
        }
        return root;
    }
};