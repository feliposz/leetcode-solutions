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
    
    int averageOfSubtree(TreeNode* root) {
        TreeNode* sumNodes = sumSubtree(root);
        TreeNode* countNodes = countSubtree(root);
        return countAverage(root, sumNodes, countNodes);
    }

    int countAverage(TreeNode* root, TreeNode* sumNodes, TreeNode* countNodes) {
        int result = 0;
        if (root) {
            result += countAverage(root->left, sumNodes->left, countNodes->left);
            result += countAverage(root->right, sumNodes->right, countNodes->right);
            if (countNodes->val > 0) {
                if (root->val == (sumNodes->val / countNodes->val)) {                    
                    result++;
                }
            }
        }
        return result;
    }

    TreeNode* sumSubtree(TreeNode* root) {
        TreeNode* node = nullptr;
        if (root) {            
            node = new TreeNode(root->val, sumSubtree(root->left), sumSubtree(root->right));
            node->val += node->left ? node->left->val : 0;
            node->val += node->right ? node->right->val : 0;
        }
        return node;
    }
    
    TreeNode* countSubtree(TreeNode* root) {
        TreeNode* node = nullptr;
        if (root) {
            node = new TreeNode(1, countSubtree(root->left), countSubtree(root->right));
            node->val += node->left ? node->left->val : 0;
            node->val += node->right ? node->right->val : 0;
        }
        return node;
    }

};