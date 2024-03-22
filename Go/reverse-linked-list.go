/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var reversed, next *ListNode
    for node := head; node != nil; node = next {
        next = node.Next
        node.Next = reversed
        reversed = node
    }
    return reversed
}