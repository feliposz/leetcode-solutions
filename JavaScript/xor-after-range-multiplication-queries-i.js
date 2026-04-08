/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var xorAfterQueries = function (nums, queries) {
    const MOD = 1e9 + 7
    const n = nums.length
    const q = queries.length
    for (let i = 0; i < q; i++) {
        const [li, ri, ki, vi] = queries[i]
        for (let idx = li; idx <= ri; idx += ki) {
            nums[idx] = (nums[idx] * vi) % MOD
        }
    }
    let result = 0
    for (let i = 0; i < n; i++) {
        result ^= nums[i]
    }
    return result
};