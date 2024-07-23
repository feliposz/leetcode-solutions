func frequencySort(nums []int) []int {
	freq := map[int]int{}
	for _, n := range nums {
		freq[n]++
	}
	values := make([]entry, 0, len(freq))
	for num, count := range freq {
		values = append(values, entry{num, count})
	}
	slices.SortFunc(values, func(a, b entry) int {
		if a.count == b.count {
			return b.num - a.num
		}
		return a.count - b.count
	})
	ans := make([]int, len(nums))
	i := 0
	for _, e := range values {
		for e.count > 0 {
			ans[i] = e.num
			e.count--
			i++
		}
	}
	return ans
}

type entry struct{ num, count int }