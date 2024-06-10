func heightChecker(heights []int) int {
    sorted := slices.Clone(heights)
    slices.Sort(sorted)
    count := 0
    for i := range heights {
        if heights[i] != sorted[i] {
            count++
        }
    }
    return count
}