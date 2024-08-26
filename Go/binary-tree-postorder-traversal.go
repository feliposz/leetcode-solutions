/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
	return post(root, []int{})
}

func post(node *TreeNode, values []int) []int {
	if node == nil {
		return values
	}
	values = post(node.Left, values)
	values = post(node.Right, values)
	values = append(values, node.Val)
	return values
}