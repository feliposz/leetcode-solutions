/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkStrings = function (s1, s2) {
    const h1odd = Array(26).fill(0)
    const h1even = Array(26).fill(0)
    const h2odd = Array(26).fill(0)
    const h2even = Array(26).fill(0)
    for (let i = 0; i < s1.length; i++) {
        const c = s1.charCodeAt(i) - 97
        if (i & 1) {
            h1odd[c]++
        } else {
            h1even[c]++
        }
    }
    for (let i = 0; i < s2.length; i++) {
        const c = s2.charCodeAt(i) - 97
        if (i & 1) {
            h2odd[c]++
        } else {
            h2even[c]++
        }
    }
    for (let i = 0; i < 26; i++) {
        if (h1odd[i] !== h2odd[i] || h1even[i] !== h2even[i]) {
            return false
        }
    }
    return true
};