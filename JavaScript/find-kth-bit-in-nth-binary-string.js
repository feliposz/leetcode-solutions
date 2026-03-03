/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
var findKthBit = function(n, k) {
    let s = Array(k).fill(0)
    let len = 1
    for (let i = 1; i < n && len < k; i++) {
        s[len++] = 1
        for (let j = len - 2; j >= 0; j--) {
            s[len++] = 1 - s[j]
        }
    }
    return s[k-1].toString(2)
};