/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
    if depth == 1 {
        return &TreeNode{val, root, nil}
    }
    if depth == -1 {
        return &TreeNode{val, nil, root}
    }
    if root != nil {
        root.Left = addOneRow(root.Left, val, abs(depth) - 1)
        root.Right = addOneRow(root.Right, val, -(abs(depth) - 1))
    }
    return root
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}