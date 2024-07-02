func intersect(nums1 []int, nums2 []int) []int {
	count := [1001]int{}
	for _, n := range nums1 {
		count[n]++
	}
    res := []int{}
	for _, n := range nums2 {
		if count[n] > 0 {
			res = append(res, n)
			count[n]--
		}
	}
	return res
}