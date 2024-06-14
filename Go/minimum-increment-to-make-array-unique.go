func minIncrementForUnique(nums []int) int {
	maxN := 0
	for _, n := range nums {
		maxN = max(maxN, n)
	}
	count := make([]int16, len(nums)+maxN)
	for _, n := range nums {
		count[n]++
	}

	moves := 0
	for n := 0; n < len(count); n++ {
		if count[n] <= 1 {
			continue
		}
		duplicates := count[n] - 1
		count[n+1] += duplicates
		moves += int(duplicates)
		// count[n] = 1
	}
	return moves
}

func SORTING_minIncrementForUnique(nums []int) int {
	slices.Sort(nums)
	moves := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] <= nums[i-1] {
			increment := nums[i-1] - nums[i] + 1
			nums[i] += increment
			moves += increment
		}
	}
	return moves
}
