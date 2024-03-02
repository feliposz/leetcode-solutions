func sortedSquares(nums []int) []int {
	result := make([]int, len(nums))
	left, right := 0, len(nums)-1
	for i := len(nums) - 1; i >= 0; i-- {
		l2, r2 := nums[left]*nums[left], nums[right]*nums[right]
		if l2 > r2 {
			result[i] = l2
			left++
		} else {
			result[i] = r2
			right--
		}
	}
	return result
}