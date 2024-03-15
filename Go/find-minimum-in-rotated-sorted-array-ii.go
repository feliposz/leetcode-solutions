func findMin(nums []int) int {
	lo := 0
	hi := len(nums) - 1
	for lo < hi {
		mid := (lo + hi) / 2
        if nums[mid] > nums[hi] {
            lo = mid + 1
        } else if nums[mid] < nums[hi] {
            hi = mid
        } else {
            hi--
        }
	}
	return nums[lo]
}