func maxFrequencyElements(nums []int) int {
    freq := make([]byte, 101)
    maxFreq := byte(0)
    maxCount := 0
    for _, num := range nums {
        freq[num]++
        if maxFreq < freq[num] {
            maxFreq = freq[num]
            maxCount = 1
        } else if maxFreq == freq[num] {
            maxCount++
        }
    }
    return maxCount * int(maxFreq)
}