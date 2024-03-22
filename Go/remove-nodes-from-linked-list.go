/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
    reversed := reverseList(head)
    prevMax := 0
    var result, next *ListNode
    for node := reversed; node != nil; node = next {
        next = node.Next
        if node.Val >= prevMax {
            node.Next = result
            result = node
            prevMax = node.Val
        }
    }
    return result
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