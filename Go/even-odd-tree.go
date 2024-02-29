/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isEvenOddTree(root *TreeNode) bool {
	type QueueEntry struct {
		Node  *TreeNode
		Level int
	}
	queue := make([]QueueEntry, 0)
	queue = append(queue, QueueEntry{root, 0})
	prevVal := -1
	prevLevel := -1
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.Level&1 == 0 {
			if curr.Node.Val&1 == 0 {
				return false
			}
			if curr.Level == prevLevel && curr.Node.Val <= prevVal {
				return false
			}
		} else {
			if curr.Node.Val&1 == 1 {
				return false
			}
			if curr.Level == prevLevel && curr.Node.Val >= prevVal {
				return false
			}
		}
		if curr.Node.Left != nil {
			queue = append(queue, QueueEntry{curr.Node.Left, curr.Level + 1})
		}
		if curr.Node.Right != nil {
			queue = append(queue, QueueEntry{curr.Node.Right, curr.Level + 1})
		}
		prevVal = curr.Node.Val
		prevLevel = curr.Level
	}
	return true
}