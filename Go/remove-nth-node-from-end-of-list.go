/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // one-pass (really?) using O(1) space

    // the scout moves ahead N positions
    scout := head
    for i := 0; i < n && scout != nil; i++ {
        scout = scout.Next
    }

    // if the end of list was rached, remove the head
    if scout == nil {
        return head.Next
    }

    // the sentinel follows exactly N positions behind the scout
    sentinel := head
    for scout.Next != nil {
        sentinel = sentinel.Next
        scout = scout.Next
    }

    // when the scout reaches the last node of the list
    // the sentinel is in position to remove the Nth node from the last
    sentinel.Next = sentinel.Next.Next

    // the case where the item to remove was the head was handled above
    return head
}

func removeNthFromEnd_v2(head *ListNode, n int) *ListNode {
    // one-pass (uses O("length of list") space)
    nodes := make([]*ListNode, 0)
    for n := head; n != nil; n = n.Next {
        nodes = append(nodes, n)
    }
    indexToRemove := len(nodes) - n
    if indexToRemove == 0 {
        return head.Next
    }
    nodes[indexToRemove - 1].Next = nodes[indexToRemove].Next
    return head
}

func removeNthFromEnd_v1(head *ListNode, n int) *ListNode {
    // two-passes (uses O(1) space)
    size := 0
    for n := head; n != nil; n = n.Next {
        size++        
    }
    removeIndex := size - n
    if removeIndex == 0 {
        return head.Next
    }
    nodeBeforeRemove := head
    for i := 0; i < removeIndex - 1; i++ {
        nodeBeforeRemove = nodeBeforeRemove.Next
    }
    nodeBeforeRemove.Next = nodeBeforeRemove.Next.Next
    return head
}