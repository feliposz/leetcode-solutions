/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func recoverFromPreorder(traversal string) *TreeNode {
	s := map[int]*TreeNode{}
	value, depth := 0, 0
	traversal += "-"
	for _, c := range traversal {
		if c == '-' {
			if value > 0 {
				node := &TreeNode{value, nil, nil}
				if depth == 0 {
					s[depth] = node
				} else {
					parent := s[depth-1]
					if parent.Left == nil {
						parent.Left = node
					} else {
						parent.Right = node
					}
					s[depth] = node
				}
				value = 0
				depth = 0
			}
			depth++
		} else {
			value = value*10 + int(c-'0')
		}
	}
	return s[0]
}