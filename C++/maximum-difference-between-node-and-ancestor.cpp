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
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root, {});
    }

    int maxAncestorDiff(TreeNode* root, vector<int> ancestors) {
        int maxDiff = 0;
        if (root) {
            for (int a: ancestors) {
                int diff = abs(root->val - a);
                maxDiff = max(maxDiff, diff);
            }
            ancestors.push_back(root->val);
            maxDiff = max(maxDiff, maxAncestorDiff(root->left, ancestors));
            maxDiff = max(maxDiff, maxAncestorDiff(root->right, ancestors));
        }
        return maxDiff;
    }
};