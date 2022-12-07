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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        
        vector<vector<int>> result;

        if (root) {
            q.push({root, 0});

            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                TreeNode* n = p.first;
                int level = p.second;

                if (level >= result.size()) {
                    result.resize(level + 1);
                }

                result[level].push_back(n->val);
                
                if (n->left) q.push({n->left, level+1});
                if (n->right) q.push({n->right, level+1});

            }
        }
        
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        
        return result;
    }
};