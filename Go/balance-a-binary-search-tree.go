/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func balanceBST(root *TreeNode) *TreeNode {
	list := buildList(root, nil)
	return buildTree(list)
}

func buildList(root *TreeNode, list []*TreeNode) []*TreeNode {
	if root == nil {
		return list
	}
	list = buildList(root.Left, list)
	list = append(list, root)
	list = buildList(root.Right, list)
	return list
}

func buildTree(list []*TreeNode) *TreeNode {
	if len(list) == 0 {
		return nil
	}
	mid := len(list) / 2
	root := list[mid]
	root.Left = buildTree(list[:mid])
	root.Right = buildTree(list[mid+1:])
	return root
}