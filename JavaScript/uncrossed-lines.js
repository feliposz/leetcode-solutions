/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxUncrossedLines = function(nums1, nums2) {
    const cache = {}
    const solve = function(i, j) {
        if (i >= nums1.length) 
            return 0
        if (j >= nums2.length)
            return 0
        const k = [i,j]
        if (cache[k] != undefined) 
            return cache[k]
        let result
        if (nums1[i] == nums2[j])
            result = 1 + solve(i + 1, j + 1)
        else
            result = Math.max(solve(i, j + 1), solve(i + 1, j))
        cache[k] = result
        return result
    }
    return solve(0, 0)
};

