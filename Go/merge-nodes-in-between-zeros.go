/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
        current := &ListNode{}
        result := current
        
        for node := head.Next; node != nil; node = node.Next {
            current.Val += node.Val
            if node.Val == 0 && node.Next != nil {
                current.Next = &ListNode{}
                current = current.Next
            }
        }
        
        return result
}