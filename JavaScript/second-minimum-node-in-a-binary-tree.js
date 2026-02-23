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
var findSecondMinimumValue = function (root) {
    const values = new Set()
    const helper = function (node) {
        if (node === null) {
            return
        }
        helper(node.left)
        values.add(node.val)
        helper(node.right)
    }
    helper(root)
    if (values.size < 2) {
        return -1
    }
    const arr = Array.from(values)
    arr.sort()
    return arr[1]
};