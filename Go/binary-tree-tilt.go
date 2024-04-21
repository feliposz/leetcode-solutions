/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    tiltSum := 0
    _ = sumAndTilt(root, &tiltSum)
    return tiltSum
}

func sumAndTilt(node *TreeNode, tiltSum *int) int {
    if node == nil {
        return 0
    }
    left := sumAndTilt(node.Left, tiltSum)
    right := sumAndTilt(node.Right, tiltSum)
    *tiltSum += abs(left - right)
    return node.Val + left + right
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}