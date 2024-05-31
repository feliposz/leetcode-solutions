func singleNumber(nums []int) []int {
    m := map[int]byte{}
    for _, x := range nums {
        m[x]++
    }
    result := make([]int, 0, 2)
    for n, count := range m {
        if count == 1 {
            result = append(result, n)
        }
    }
    return result
}