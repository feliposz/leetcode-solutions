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

function maxLevelSum(root: TreeNode | null): number {
    const levelSum: Array<number> = []
    const queue: Array<[TreeNode, number]> = []
    queue.push([root, 1])
    while (queue.length > 0) {
        const [node, level] = queue.splice(0, 1)[0]
        levelSum[level] = (levelSum[level] ?? 0) + node.val
        if (node.left !== null) {
            queue.push([node.left, level+1])
        }
        if (node.right !== null) {
            queue.push([node.right, level+1])
        }
    }
    let maxSum: number = -Infinity
    let minLevel: number = 0
    for (let i = 0; i < levelSum.length; i++) {
        if (levelSum[i] !== undefined) {
            if (maxSum < levelSum[i]) {
                maxSum = levelSum[i]
                minLevel = i
            }
        }
    }
    return minLevel
};