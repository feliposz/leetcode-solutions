func maxWidthRamp(nums []int) int {
	stack := []int{0}
	ans := 0
	for i := 1; i < len(nums); i++ {
		top := stack[len(stack)-1]
		if nums[i] < nums[top] {
			stack = append(stack, i)
		}
	}
	for i := len(nums) - 1; i >= 0; i-- {
		for len(stack) > 0 {
			top := stack[len(stack)-1]
			if nums[top] > nums[i] {
				break
			}
			ans = max(ans, i-top)
			stack = stack[:len(stack)-1]
		}
	}
	return ans
}