func findMatrix(nums []int) [][]int {
    
    // count how many times each distinct number appears
    freq := map[int]int{}
    maxFreq := 0 // most repeated number
    for _, n := range nums {
        freq[n]++
        maxFreq = max(maxFreq, freq[n])
    }

    // since each row must have distinct numbers,
    // we need at minimum the count of the most repeated number    
    result := make([][]int, maxFreq)
    for i := range result {
        result[i] = make([]int, 0)
    }

    // distribute each distinct number on the rows
    for n, count := range freq {
        for i := range result {
            if i < count {
                result[i] = append(result[i], n)
            } else {
                break
            }            
        }
    }

    return result
}