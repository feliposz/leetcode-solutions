/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const hist = {}
    for (const n of nums) {
        hist[n] = (hist[n] || 0) + 1
    }
    const ans = []
    while (k > 0) {
        let maxFreq = -1
        let maxElem = null
        for (const [elem, freq] of Object.entries(hist)) {
            if (maxFreq < freq) {
                maxFreq = freq
                maxElem = elem
            }
        }
        ans.push(maxElem)
        hist[maxElem] = 0
        k--
    }
    return ans
};