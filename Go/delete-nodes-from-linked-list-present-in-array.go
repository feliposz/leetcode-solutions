/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
	slices.Sort(nums)
	tmp := &ListNode{0, head}
	for node := tmp; node.Next != nil; {
		if _, found := slices.BinarySearch(nums, node.Next.Val); found {
			node.Next = node.Next.Next
		} else {
			node = node.Next
		}
	}
	return tmp.Next
}