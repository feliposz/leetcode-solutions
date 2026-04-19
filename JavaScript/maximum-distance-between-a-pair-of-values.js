/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function(nums1, nums2) {
    let i = 0
    let j = 0
    let dist = 0
    const n1 = nums1.length
    const n2 = nums2.length
    while (i < n1 && j < n2) {
        if (nums1[i] <= nums2[j]) {
            dist = Math.max(dist, j - i)
            j++
        } else if (i < j) {
            i++
        } else {
            j++
        }
    }
    return dist
};