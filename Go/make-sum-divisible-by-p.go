func minSubarray(nums []int, p int) int {
	total := 0
	for _, x := range nums {
		total += x
	}
	if total%p == 0 {
		return 0
	}
	for size := 1; size < len(nums); size++ {
		sub := 0
		i := 0
		for i < size-1 {
			sub += nums[i]
			i++
		}
		for i < len(nums) {
			sub += nums[i]
			if (total-sub)%p == 0 {
				return size
			}
			i++
			sub -= nums[i-size]
		}
	}
	return -1
}