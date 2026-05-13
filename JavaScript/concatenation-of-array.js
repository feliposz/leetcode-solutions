/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function (nums) {
    const n = nums.length
    const result = Array(n)
    for (let i = 0; i < n; i++) {
        result[i] = result[i + n] = nums[i]
    }
    return result
};