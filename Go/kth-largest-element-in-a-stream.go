type KthLargest struct {
	k    int
	nums []int
}

func Constructor(k int, nums []int) KthLargest {
	slices.Sort(nums)
	return KthLargest{k, nums}
}

func (this *KthLargest) Add(val int) int {
	pos, _ := slices.BinarySearch(this.nums, val)
	this.nums = slices.Insert(this.nums, pos, val)
	return this.nums[len(this.nums)-this.k]
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */