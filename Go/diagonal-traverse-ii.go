func findDiagonalOrder(nums [][]int) []int {
	size := 0
	for i := range nums {
		size += len(nums[i])
	}
	result := make([]int, 0, size)

	diagonals := map[int][]int{}

	lastDiag := 0
	for i := range nums {
		for j, val := range nums[i] {
			if _, ok := diagonals[i+j]; !ok {
				diagonals[i+j] = make([]int, 0)
			}
			diagonals[i+j] = append(diagonals[i+j], val)
			//diagonals[i+j] = append([]int{val}, diagonals[i+j]...)
			lastDiag = max(lastDiag, i+j)
		}
	}

	for i := 0; i <= lastDiag; i++ {
		for j := len(diagonals[i]) - 1; j >= 0; j-- {
			result = append(result, diagonals[i][j])
		}
	}
	return result
}