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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n == 1) {
            ans.push_back(new TreeNode(0));
        } else if (n % 2 == 1) {
            for (int x = 0; x < n; x++) {
                int y = n - 1 - x;
                for (auto left: allPossibleFBT(x)) {
                    for (auto right: allPossibleFBT(y)) {
                        ans.push_back(new TreeNode(0, left, right));
                    }
                }
            }
        }
        return ans;
    }
};