/**
 * @param {number} n
 * @return {number}
 */
var concatenatedBinary = function(n) {
    const mod = 1000000007n
    let result = 0n
    let limit = 1n
    let shift = 0n
    for (let i = 1n; i <= BigInt(n); i++) {
        if (i >= limit) {
            limit += limit
            shift++
        }
        result = ((result << shift) | i) % mod
    }
    return Number(result)
};