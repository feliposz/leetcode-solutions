func maximumCount(nums []int) int {
	lo, hi := 0, len(nums)-1
	for lo <= hi {
		mid := (lo + hi) / 2
		if nums[mid] < 0 {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	neg := lo
	lo, hi = 0, len(nums)-1
	for lo <= hi {
		mid := (lo + hi) / 2
		if nums[mid] > 0 {
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	pos := len(nums) - hi - 1
	return max(neg, pos)
}