func beautifulSubsets(nums []int, k int) int {
	slices.Sort(nums)
	seen := map[int]int{}
	count := countBeautifulSubsets(nums, seen, 0, k)
	return count - 1
}

func countBeautifulSubsets(nums []int, seen map[int]int, i int, k int) int {
	if i >= len(nums) {
		return 1
	}
	count := countBeautifulSubsets(nums, seen, i+1, k)
	if seen[nums[i]-k] == 0 {
		seen[nums[i]]++
		count += countBeautifulSubsets(nums, seen, i+1, k)
		seen[nums[i]]--
	}
	return count
}

func SLOW_beautifulSubsets(nums []int, k int) int {
	size := len(nums)
	limit := 1 << size
	count := 0
	// loop over all possible bit combinations (representing sets)
	for i := 1; i < limit; i++ {
		beautiful := true
	loop_j:
		for x := 0; x < size; x++ {
			if i&(1<<x) > 0 {
				// if element at index x is part of set, check other present elements
				for y := x + 1; y < size; y++ {
					if i&(1<<y) > 0 {
						switch nums[x] - nums[y] {
						case k, -k:
							beautiful = false
							break loop_j
						}
					}
				}
			}
		}
		// no conflicts in this subset
		if beautiful {
			count++
		}
	}
	return count
}