# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        node = head
        count = 0
        while node:
            count += 1
            node = node.next
        removeN = count - n
        if removeN == 0:
            return head.next
        node = head
        while removeN > 1:
            removeN -= 1
            node = node.next
        node.next = node.next.next
        return head

        