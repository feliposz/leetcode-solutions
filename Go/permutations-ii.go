func permuteUnique(nums []int) [][]int {
	size := len(nums)
	num_count := map[int]int{}
	for _, n := range nums {
		num_count[n]++
	}
	result := [][]int{}
	temp := make([]int, 0, size)
	var helper func(temp []int)
	helper = func(temp []int) {
		if len(temp) == size {
			result = append(result, slices.Clone(temp))
			return
		}
		for num, count := range num_count {
			if count > 0 {
				num_count[num]--
				temp = append(temp, num)
				helper(temp)
				temp = temp[:len(temp)-1]
				num_count[num]++
			}
		}
	}
	helper(temp)
	return result
}
