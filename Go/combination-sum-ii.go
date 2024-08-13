func combinationSum2(candidates []int, target int) [][]int {
	// reset temporary result from previous executions
	result = [][]int{}
	// keep candidates sorted to allow for early return
	slices.Sort(candidates)
	helper(candidates, target, 0, 0, nil)
	return result
}

var result [][]int

func helper(candidates []int, target int, i int, sum int, temp []int) {
	// if target was reached, add current combination to result
	if target == sum {
		result = append(result, temp)
		return
	}
	// all candidates considered
	if i == len(candidates) {
		return
	}
	curr := candidates[i]
	// early return, since next candidates will produce sums larger than target
	if sum+curr > target {
		return
	}
	// recurse case for combination that includes current
	helper(candidates, target, i+1, sum+curr, append(slices.Clone(temp), curr))
	// skip current candidate and all the candidates with the same value
	for i < len(candidates) && candidates[i] == curr {
		i++
	}
	helper(candidates, target, i, sum, temp)
}