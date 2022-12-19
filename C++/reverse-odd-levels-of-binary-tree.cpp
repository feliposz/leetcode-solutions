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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>> levels;

        queue<pair<TreeNode*,int>> q;
        
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level + 1 > levels.size()) {
                levels.resize(level + 1);
            }
            levels[level].push_back(node);

            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }

        int nlevels = levels.size();

        for (int level = 1; level < nlevels; level += 2) {
            int i = 0, j = levels[level].size() - 1;
            while (i < j) {
                swap(levels[level][i]->val, levels[level][j]->val);
                i++;
                j--;
            }
        }

        return root;
    }

    void reverseOddLevels(TreeNode* root, int level) {
        if (root) {
            if (level % 2 == 0 && root->left && root->right) {
                swap(root->left->val, root->right->val);
            }
            reverseOddLevels(root->left, level + 1);
            reverseOddLevels(root->right, level + 1);
        }
    }
};