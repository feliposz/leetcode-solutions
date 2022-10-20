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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        traverse(root1, list1);
        traverse(root2, list2);
        vector<int> answer;
        
        int i = 0, j = 0;
        int sz1 = list1.size(), sz2 = list2.size();
        while ((i < sz1) && (j < sz2)) {
            if (list1[i] < list2[j]) {
                answer.push_back(list1[i++]);
            } else {                
                answer.push_back(list2[j++]);
            }
        }
        while (i < sz1) {
            answer.push_back(list1[i++]);
        }
        while (j < sz2) {
            answer.push_back(list2[j++]);
        }
        return answer;
    }
    
    void traverse(TreeNode* root, vector<int> &list) {
        if (root) {
            traverse(root->left, list);
            list.push_back(root->val);
            traverse(root->right, list);
        }
    }
};