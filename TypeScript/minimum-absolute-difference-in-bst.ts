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

function getMinimumDifference(root: TreeNode | null): number {
    let minDiff = 1000000
    let prev = 1000000
    const walk = (node: TreeNode | null): void => {
        if (node !== null) {
            walk(node.left)
            const diff = Math.abs(node.val - prev)
            prev = node.val
            if (minDiff > diff) {
                minDiff = diff
            }
            walk(node.right)
        }
    }
    walk(root)
    return minDiff
};