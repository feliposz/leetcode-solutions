func maxSubarrayLength(nums []int, k int) int {
    freq := map[int]int{}
    left, maxLength := 0, 0
    for right, num := range nums {
        freq[num]++
        for freq[num] > k {
            freq[nums[left]]--
            left++
        }
        maxLength = max(maxLength, right - left + 1)
    }
    return maxLength
}