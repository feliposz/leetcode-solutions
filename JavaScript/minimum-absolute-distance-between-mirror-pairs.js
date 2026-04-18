/**
 * @param {number[]} nums
 * @return {number}
 */
var minMirrorPairDistance = function(nums) {
    const m = new Map()
    let min = Infinity
    for (let i = 0; i < nums.length; i++) {
        let n = nums[i]
        if (m.has(n)) {
            min = Math.min(min, i - m.get(n))
        }
        const r = reverse(n)
        m.set(r, i)
    }
    return min === Infinity ? -1 : min
};

var reverse = function(x) {
    let y = 0
    while (x > 0) {
        y = (y * 10) + (x % 10)
        x = Math.trunc(x / 10)
    }
    return y
}