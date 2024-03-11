func intersection(nums1 []int, nums2 []int) []int {
    m := make(map[int]byte)
    for _, n := range nums1 {
        m[n] = 1
    }
    for _, n := range nums2 {
        if m[n] == 1 {
            m[n] = 2
        }
    }
    result := make([]int, 0, len(m))
    for k, v := range m {
        if v == 2 {
            result = append(result, k)
        }
    }
    return result
}