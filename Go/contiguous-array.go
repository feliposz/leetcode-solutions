func findMaxLength(nums []int) int {
	firstMap := make(map[int]int)
    count := 0
    maxLen := 0
    firstMap[0] = -1
	for i, v := range nums {
        if v == 1 {
            count++
        } else {
            count--
        }
        if firstIndex, found := firstMap[count]; found {
            length := i - firstIndex
            maxLen = max(maxLen, length)
        } else {
            firstMap[count] = i
        }
	}
	return maxLen
}
