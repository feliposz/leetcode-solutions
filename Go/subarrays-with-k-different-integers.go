func subarraysWithKDistinct(nums []int, k int) int {
	lessOrEqualToK := subarraysWithUpToKDistinct(nums, k)
	lessThanK := subarraysWithUpToKDistinct(nums, k-1)
	return lessOrEqualToK - lessThanK
}

func subarraysWithUpToKDistinct(nums []int, k int) int {
    freq := map[int]int{}
	result, left := 0, 0
	for right, num := range nums {
		freq[num]++
		for len(freq) > k {
			other := nums[left]
            freq[other]--
			if freq[other] == 0 {
				delete(freq, other)
			}
			left++
		}
		result += right - left + 1
	}
    return result
}