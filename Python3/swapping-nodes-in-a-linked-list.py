# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        node = head
        count = 0
        while node:
            count += 1
            node = node.next
        k2 = count - k + 1

        node = head
        nodeA = None
        nodeB = None
        i = 1
        while node:
            if i == k:
                nodeA = node
            if i == k2:
                nodeB = node
            i += 1
            node = node.next
            if nodeA and nodeB:
                break
        nodeA.val, nodeB.val = (nodeB.val, nodeA.val)

        return head