/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    const h1 = Array(26).fill(0)
    const h2 = Array(26).fill(0)
    for (let i = 0; i < word1.length; i++) {
        const c = word1.charCodeAt(i) - 97
        h1[c]++
    }
    for (let i = 0; i < word2.length; i++) {
        const c = word2.charCodeAt(i) - 97
        h2[c]++
    }
    for (let i = 0; i < 26; i++) {
        if ((h1[i] === 0) !== (h2[i] === 0)) {
            return false
        }
    }
    h1.sort()
    h2.sort()
    for (let i = 0; i < 26; i++) {
        if (h1[i] !== h2[i]) {
            return false
        }
    }
    return true
};