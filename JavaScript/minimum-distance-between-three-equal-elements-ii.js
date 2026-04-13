/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDistance = function (nums) {
    const m = new Map()
    for (let i = 0; i < nums.length; i++) {
        const n = nums[i]
        if (!m.has(n)) {
            m.set(n, [])
        }
        m.get(n).push(i)
    }
    // console.table(m)
    let result = Infinity
    for (const [n, tuple] of m) {
        for (let x = 0; x < tuple.length - 2; x++) {
            const i = tuple[x]
            const j = tuple[x + 1]
            const k = tuple[x + 2]
            // console.log(i, j, k)
            const dist = Math.abs(i - j) + Math.abs(j - k) + Math.abs(k - i)
            // console.log(dist)
            result = Math.min(result, dist)
        }
    }
    return result === Infinity ? -1 : result
};