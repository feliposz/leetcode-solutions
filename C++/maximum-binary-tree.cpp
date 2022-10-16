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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int a, int b) {
        TreeNode* ans = nullptr;
        if (a <= b) {
            int index = a;
            int max = nums[a];
            for (int i = a+1; i <= b; i++) {
                if (nums[i] > max) {
                    index = i;
                    max = nums[i];
                }
            }
            ans = new TreeNode(nums[index], 
                               constructMaximumBinaryTree(nums, a, index - 1),
                               constructMaximumBinaryTree(nums, index + 1, b));
        }
        return ans;
    }
};