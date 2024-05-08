/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
    carry := doubleHelper(head)
    if carry > 0 {
        return &ListNode{carry, head}
    }
    return head
}

func doubleHelper(node *ListNode) int {
    if node == nil {
        return 0
    }
    double := node.Val * 2 + doubleHelper(node.Next)
    node.Val = double % 10
    return double / 10
}