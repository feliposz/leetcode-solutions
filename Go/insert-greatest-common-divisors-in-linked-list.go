/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
    for n := head; n.Next != nil; n = n.Next.Next {
        n.Next = &ListNode{gcd(n.Val, n.Next.Val), n.Next}
    }
    return head
}

func gcd(x, y int) int {
    for y != 0 {
        x, y = y, x % y
    }
    return x
}