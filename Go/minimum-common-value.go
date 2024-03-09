func getCommon(nums1 []int, nums2 []int) int {
    i1, i2, sz1, sz2 := 0, 0, len(nums1), len(nums2)
    for i1 < sz1 && i2 < sz2 {
        if nums1[i1] == nums2[i2] {
            return nums1[i1]
        } else if nums1[i1] < nums2[i2] {
            i1++
        } else {
            i2++
        }
    }
    return -1
}