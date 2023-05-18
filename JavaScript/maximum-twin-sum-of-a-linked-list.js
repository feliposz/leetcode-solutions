/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
    const values = []
    for (let node = head; node; node = node.next) {
        values.push(node.val)
    }
    let maxSum = values[0] + values[values.length - 1]
    for (let i = 0, j = values.length - 1; i < j; i++, j--) {
        const sum = values[i] + values[j]
        if (maxSum < sum)
            maxSum = sum
    }
    return maxSum
};