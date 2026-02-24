/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumRootToLeaf = function (root, acc = 0) {
    if (!root) {
        return 0
    }
    const val = (acc << 1) | root.val
    if (!root.left && !root.right) {
        return val
    }
    return sumRootToLeaf(root.left, val) + sumRootToLeaf(root.right, val)
};