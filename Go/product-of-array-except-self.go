func productExceptSelf(nums []int) []int {
	n := len(nums)
	result := make([]int, n)
	prod := 1
	for i := 0; i < n; i++ {
        result[i] = prod
        prod *= nums[i]
	}
	prod = 1
	for i := n - 1; i >= 0; i-- {
		result[i] *= prod
        prod *= nums[i]
	}
	return result
}