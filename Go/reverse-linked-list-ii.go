/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    // empty list or "1-element reversal"
    if head == nil || left == right {
        return head
    }

    // start with a dummy node because we might need to change the head if left == 1
    dummy := &ListNode{0, head}
    i := 0
    
    // find the first node to be reversed
    prefix := dummy
    for i < left - 1 {
        prefix = prefix.Next
        i++
    }
    //fmt.Println(prefix)

    // find the node after the last to be reversed (may be nil if right is the last element)
    tail := prefix
    for i <= right {
        tail = tail.Next
        i++
    }
    //fmt.Println(tail)

    // start pushing elements into reversed (as a stack)
    reversed := tail
    var next *ListNode
    for node := prefix.Next; node != tail; node = next {
        //fmt.Println(node)
        next = node.Next
        node.Next = reversed
        reversed = node
    }

    // glue the last node of the prefix with the reversed list
    prefix.Next = reversed
    return dummy.Next
}