func circularArrayLoop(nums []int) bool {
	// get index for next element
	next := func(i int) int {
		j := (i + nums[i]) % len(nums)
		if j < 0 {
			j += len(nums)
		}
		return j
	}

	for i := range nums {
		visited := make([]bool, len(nums))
        positive := nums[i] > 0

        // check cycles with the same sign
        for !visited[i] && nums[i] > 0 == positive {
			visited[i] = true
            j := next(i)
            if j == i {
                break // 1-element cycle
            }
            i = j
		}
		
        // last element visited points to first (complete cycle)
		if visited[i] && i != next(i) {
            return true
        }
	}
	return false
}
