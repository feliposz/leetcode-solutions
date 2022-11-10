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
class FindElements {
public:
    TreeNode* tree;
        
    FindElements(TreeNode* root) {
        recover(root, 0);
        tree = root;
    }
    
    void recover(TreeNode* root, int val) {
        if (root) {
            root->val = val;
            recover(root->left, val * 2 + 1);
            recover(root->right, val * 2 + 2);
        }
    }
    
    bool find(int target) {
        return find(tree, target);
    }
    
    bool find(TreeNode* root, int target)
    {
        if (root) {
            if (root->val == target) {
                return true;
            }
            if (root->val < target) {
                return find(root->left, target) || find(root->right, target);
            }
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */