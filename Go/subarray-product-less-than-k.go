func numSubarrayProductLessThanK(nums []int, k int) int {
    
    if k == 0 {
        return 0
    }

    prod, count, left := 1, 0, 0

    for right := range nums {
        prod *= nums[right]
        for left <= right && prod >= k {
            prod /= nums[left]
            left++
        }
        count += right - left + 1
    }

    return count
    
}