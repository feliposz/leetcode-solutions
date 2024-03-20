/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    // find the insertion point (just before the Ath position)
    insertion := list1
    i := 0
    for i < a - 1 {
        insertion = insertion.Next
        i++
    }
    // find the "cut" point, or the tail of the list that will be kept (after the Bth position)
    tail := insertion
    for i < b {
        tail = tail.Next
        i++
    }
    // insert list2 after (A-1)th position
    insertion.Next = list2
    // insert tail at the end of list2
    for n := list2; n != nil; n = n.Next {
        if n.Next == nil {
            n.Next = tail.Next
            tail.Next = nil // NOTE: technically not needed, but to keep things tidy
            break
        }
    }
    // NOTE: the problem doesn't account for a = 0, but if it was possible, we'd have to return the head of list2
    if a == 0 {
        return list2
    }
    return list1
}