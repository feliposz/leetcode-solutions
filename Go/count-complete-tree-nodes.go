/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func countNodes(root *TreeNode) int {
	// Check height of the tree (left is always complete)
	height := 0
	for n := root; n != nil; n = n.Left {
		height++
	}

	// Calculate the total number of nodes if all the levels were complete
	complete := 0
	for h := 0; h < height; h++ {
		complete += 1 << h //(same as 2^h)
	}

	// Count the missing nodes
	missing := countMissing(root, height)

	return complete - missing
}

func countMissing(node *TreeNode, height int) int {
	if node == nil {
		if height == 1 {
			// reached the lowest level, but node is missing
			return 1
		}
		return 0
	}

	right := countMissing(node.Right, height-1)
	if right == 0 {
		// if there are no missing node on the right branch, no need to count the left
		return 0
	}
	left := countMissing(node.Left, height-1)
	return right + left
}