/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    // find the middle of the list
    slow, fast := head, head.Next
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    // reverse the second half
    reversed := reverseList(slow.Next)
    slow.Next = nil

    // interleave elements
    var aNext, bNext *ListNode
    for a, b := head, reversed; b != nil; a, b = aNext, bNext {
        aNext, bNext = a.Next, b.Next
        a.Next = b
        b.Next = aNext
    }
}

func reverseList(head *ListNode) *ListNode {
    var reversed, next *ListNode
    for node := head; node != nil; node = next {
        next = node.Next
        node.Next = reversed
        reversed = node
    }
    return reversed
}