/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
	return sumRootToLeaf(root, 0)
}

func sumRootToLeaf(node *TreeNode, val int) int {
	if node == nil {
		return 0
	}
    pathSum := node.Val + val*10
	if node.Left == nil && node.Right == nil {
		return pathSum
	}
	return sumRootToLeaf(node.Left, pathSum) +
		sumRootToLeaf(node.Right, pathSum)
}