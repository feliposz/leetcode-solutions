/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeZeroSumSublists(head *ListNode) *ListNode {
    newHead := head
    var prev *ListNode = nil
    for i := head; i != nil; {
        sum := 0
        advance := true
        for j := i; j != nil; j = j.Next {
            sum += j.Val
            if sum == 0 {
                if prev == nil {
                    newHead = j.Next
                } else {
                    prev.Next = j.Next
                }
                i = j.Next
                advance = false
                break
            }
        }
        if advance {
            prev = i
            i = i.Next
        }
    }
    return newHead
}

