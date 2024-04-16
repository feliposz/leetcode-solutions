/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
    return helper(root, val, depth, null);
}

function helper(root: TreeNode | null, val: number, depth: number, isLeft: boolean | null): TreeNode | null {
    if (depth === 1) {
        if (isLeft === null || isLeft === true) {
            return new TreeNode(val, root, null);
        } else {
            return new TreeNode(val, null, root);
        }
    }
    if (root) {
        root.left = helper(root.left, val, depth - 1, true);
        root.right = helper(root.right, val, depth - 1, false);
    }
    return root;
};