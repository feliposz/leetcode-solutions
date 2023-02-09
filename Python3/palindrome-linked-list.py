# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        data = []
        node = head
        size = 0
        while node != None:
            data.append(node.val)
            node = node.next
            size += 1
        i = 0
        j = size - 1
        while i < j:
            if data[i] != data[j]:
                return False
            i += 1
            j -= 1
        return True
        