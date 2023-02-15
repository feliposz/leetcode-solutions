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
    vector<int> values;

    int kthSmallest(TreeNode* root, int k)
    {
        if (root)
        {
            kthSmallest(root->left, k);
            values.push_back(root->val);
            kthSmallest(root->right, k);
        }
        if (values.size() >= k)
            return values[k - 1];
        else
            return INT32_MIN;
    }
};