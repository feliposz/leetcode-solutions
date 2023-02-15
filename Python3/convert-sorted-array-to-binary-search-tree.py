# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.build(nums, 0, len(nums) - 1)
    
    def build(self, nums: List[int], lo: int, hi: int) -> Optional[TreeNode]:
        if lo <= hi:
            mid = (lo + hi) // 2
            left = self.build(nums, lo, mid-1)
            right = self.build(nums, mid+1, hi)
            node = TreeNode(nums[mid], left, right)
            return node
        return None
