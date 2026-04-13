/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function (nums, target, start) {
    for (let dist = 0; ; dist++) {
        const right = start + dist
        const left = start - dist
        if (right < nums.length && nums[right] === target) {
            return dist
        } else if (left >= 0 && nums[left] === target) {
            return dist
        } else if (left < 0 && right >= nums.length) {
            break
        }
    }
    return -1
};