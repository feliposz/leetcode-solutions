/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func bstToGst(root *TreeNode) *TreeNode {
    var sum = 0
	helper(root, &sum)
    return root
}

func helper(root *TreeNode, sum *int) {
    if root == nil {
		return
	}
	helper(root.Right, sum)
	root.Val += *sum
	*sum = root.Val
	helper(root.Left, sum)
}
