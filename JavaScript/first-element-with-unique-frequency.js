/**
 * @param {number[]} nums
 * @return {number}
 */
var firstUniqueFreq = function (nums) {
    const freq = new Map()
    for (const x of nums) {
        freq.set(x, (freq.get(x) || 0) + 1)
    }
    const freqCount = new Map()
    for (const f of freq.values()) {
        freqCount.set(f, (freqCount.get(f) || 0) + 1)
    }
    for (const x of nums) {
        const f = freq.get(x)
        if (freqCount.get(f) === 1) {
            return x
        }
    }
    return -1
};