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
class BSTIterator {
public:
    queue<int> data;
    
    BSTIterator(TreeNode* root) {
        fill(root);
    }
    
    void fill(TreeNode* root) {
        if (root) {
            fill(root->left);
            data.push(root->val);
            fill(root->right);
        }
    }
    
    int next() {
        int n = data.front();
        data.pop();
        return n;
    }
    
    bool hasNext() {
        return !data.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */