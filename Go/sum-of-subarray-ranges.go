func subArrayRanges(nums []int) int64 {
	var sum int64
	for i := 0; i < len(nums); i++ {
		lo, hi := nums[i], nums[i]
		for j := i; j < len(nums); j++ {
			lo = min(lo, nums[j])
			hi = max(hi, nums[j])
			sum += int64(hi - lo)
		}
	}
	return sum
}