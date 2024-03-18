/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
	values := make([]int, 0, 20000)
    for node := head; node != nil; node = node.Next {
		values = append(values, node.Val)
	}
    var makeTree func (i, j int) *TreeNode
    makeTree = func (i, j int) *TreeNode {
        if i > j {
            return nil
        }
        mid := (i + j) >> 1
        return &TreeNode{values[mid], makeTree(i, mid-1), makeTree(mid+1, j)}
    }
	return makeTree(0, len(values)-1)
}
