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
var swapNodes = function(head, k) {
    let current = head

    // count elements
    let len = 0
    while (current !== null) {
        current = current.next
        len++
    }

    let first = null
    let second = null

    current = head
    let index = 1
    while (current !== null) {
        if (index == k) {
            first = current
        }
        if (index == len - k + 1) {
            second = current
        }
        current = current.next
        index++
    }

    const tmp = first.val
    first.val = second.val
    second.val = tmp
    return head
};