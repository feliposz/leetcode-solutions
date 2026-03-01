/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(nums) {
    let prev = nums[0]
    let count = 0
    let max = 1
    for (let x of nums) {
        if (x > prev) {
            count++
            max = Math.max(max, count)
        } else {
            count = 1
        }
        prev = x
    }
    return max
};