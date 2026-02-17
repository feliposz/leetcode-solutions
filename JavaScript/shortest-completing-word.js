/**
 * @param {string} licensePlate
 * @param {string[]} words
 * @return {string}
 */
var shortestCompletingWord = function(licensePlate, words) {
    const h = Array(26).fill(0)
    const lpLower = licensePlate.toLowerCase()
    for (let i = 0; i < licensePlate.length; i++) {
        const c = lpLower.charCodeAt(i) - 97
        if (c >= 0 && c < 26) {
            h[c]++
        }
    }
    let candidate = null
    for (let w of words) {
        const g = Array(26).fill(0)
        const wLower = w.toLowerCase()
        for (let i = 0; i < w.length; i++) {
            g[wLower.charCodeAt(i) - 97]++
        }
        let valid = true
        for (let c in h) {
            if (g[c] < h[c]) {
                valid = false
                break
            }
        }
        if (valid) {
            if (candidate === null || candidate.length > w.length) {
                candidate = w
            }
        }
    }
    return candidate
};