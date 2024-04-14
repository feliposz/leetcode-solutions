/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
    if root == nil {
        return 0
    }
    sum := sumOfLeftLeaves(root.Right)
    if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
        sum += root.Left.Val
    } else {
        sum += sumOfLeftLeaves(root.Left)
    }
    return sum
}