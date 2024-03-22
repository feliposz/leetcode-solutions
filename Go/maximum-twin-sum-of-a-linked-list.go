/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {
    // find the middle of the list
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    // reverse the second half
    reversed := reverseList(slow)

    maxSum := 0
    // compare first half with reversed second half
    for a, b := head, reversed; b != nil; a, b = a.Next, b.Next {
        maxSum = max(maxSum, a.Val + b.Val)
    }

    // (if needed) restore the second half
    // _ = reverseList(reversed)

    return maxSum    
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