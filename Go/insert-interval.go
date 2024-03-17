func insert(intervals [][]int, newInterval []int) [][]int {
    // insert interval at expected position
    insertPosition, _ := slices.BinarySearchFunc(intervals, newInterval, func (a, b []int) int { 
        return a[0] - b[0] 
    })
    intervals = slices.Insert(intervals, insertPosition, newInterval)

    // merge any intervals that overlap
    result := [][]int{intervals[0]}
    last := 0
    for i := 1; i < len(intervals); i++ {
        if intervals[i][0] <= result[last][1] && intervals[i][1] >= result[last][0] {
            //result[last][0] = min(result[last][0], intervals[i][0])
            result[last][1] = max(result[last][1], intervals[i][1])
        } else {
            result = append(result, intervals[i])
            last++
        }
    }
    return result
}