/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
    // calculate total list size
    let size = 0
    let tail = null
    for (let node = head; node; node = node.next) {
        size++
        if (node.next == null) {
            tail = node
        }
    }
    // handle cycles...
    k %= size
    if (size < 2 || k === 0) {
        return head
    }
    const splitPoint = size - k
    let beforeSplit = null
    let splitNode = head
    for (let i = 0; i < splitPoint; i++) {
        beforeSplit = splitNode
        splitNode = splitNode.next
    }
    const newHead = splitNode
    tail.next = head
    beforeSplit.next = null
    return newHead
};