func subarraySum(nums []int, k int) int {
	size := len(nums)
	count, sum := 0, 0
    sumOccurrencesMap := make(map[int]int)
    sumOccurrencesMap[0] = 1
	for i := 0; i < size; i++ {
		sum += nums[i]
		if occurrences, found := sumOccurrencesMap[sum - k]; found {
			count += occurrences
		}
		sumOccurrencesMap[sum] += 1
	}
	return count
}