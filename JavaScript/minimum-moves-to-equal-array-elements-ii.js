/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    nums.sort((a, b) => a - b)
    const mid = Math.floor(nums.length/2)
    const median = nums[mid]
    let diff = 0
    for (let x of nums) {
        diff += Math.abs(x - median)
    }
    return diff
};