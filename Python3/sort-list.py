# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        values = defaultdict(lambda: 0)
        node = head
        while node:
            values[node.val] += 1
            node = node.next
        result = None
        for k, v in sorted(values.items(), reverse=True):
            for _ in range(v):
                result = ListNode(k, result)
        return result

