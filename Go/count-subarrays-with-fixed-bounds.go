func countSubarrays(nums []int, minK int, maxK int) int64 {
    result := int64(0)
    minI, maxI, badI := -1, -1, -1
    for i := range nums {
        if nums[i] == minK {
            minI = i
        }
        if nums[i] == maxK {
            maxI = i
        }
        if nums[i] < minK || nums[i] > maxK {
            badI = i
        }
        subarrays := max(0, min(minI, maxI) - badI)
        result += int64(subarrays)
    }
    return result
}