func distance(nums []int) []int64 {
	arr := make([]int64, len(nums))
	numIndices := make(map[int][]int64)
	for index, num := range nums {
		if _, ok := numIndices[num]; !ok {
			numIndices[num] = make([]int64, 0)
		}
		numIndices[num] = append(numIndices[num], int64(index))
	}
	for _, indices := range numIndices {
		totalSum := int64(0)
		for _, index := range indices {
			totalSum += int64(index)
		}
		preSum := int64(0)
		size := int64(len(indices))
		for position, index := range indices {
			arr[index] += index * (2 * int64(position) - size) - 2 * preSum + totalSum 
			preSum += index
		}
	}
	return arr
}
