/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func spiralMatrix(m int, n int, head *ListNode) [][]int {
	mat := make([][]int, m)
	for i := range mat {
		mat[i] = make([]int, n)
		for j := range mat[i] {
			mat[i][j] = -1
		}
	}
	row, col := 0, 0
	top, left, bot, right := 0, 0, m-1, n-1
	node := head
	for node != nil {
		for node != nil {
			mat[row][col] = node.Val
			node = node.Next
			if col == right {
				row++
				top++
				break
			}
			col++
		}
		for node != nil {
			mat[row][col] = node.Val
			node = node.Next
			if row == bot {
				col--
				right--
				break
			}
			row++
		}
		for node != nil {
			mat[row][col] = node.Val
			node = node.Next
			if col == left {
				row--
				bot--
				break
			}
			col--
		}
		for node != nil {
			mat[row][col] = node.Val
			node = node.Next
			if row == top {
				col++
				left++
				break
			}
			row--
		}
	}
	return mat
}