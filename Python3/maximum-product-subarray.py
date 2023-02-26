class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxProd = minProd = ans = nums[0]
        for i in range(1, len(nums)):
            maxTmp = maxProd * nums[i]
            minTmp = minProd * nums[i]
            maxNew = max(nums[i], maxTmp, minTmp)
            minNew = min(nums[i], maxTmp, minTmp)
            maxProd = maxNew
            minProd = minNew
            ans = max(maxProd, ans)
        return ans
