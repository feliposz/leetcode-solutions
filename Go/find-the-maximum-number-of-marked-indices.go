func maxNumOfMarkedIndices(nums []int) int {
	slices.Sort(nums)
	n := len(nums)
	i, j := 0, n/2
	count := 0
	for i < n/2 && j < n {
		if nums[i]*2 <= nums[j] {
            //fmt.Println(nums[i], nums[j])
			count += 2
			i++
			j++
		} else {
			j++
		}
	}
	return count
}