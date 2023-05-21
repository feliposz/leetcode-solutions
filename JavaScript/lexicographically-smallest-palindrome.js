/**
 * @param {string} s
 * @return {string}
 */
var makeSmallestPalindrome = function(s) {
    let op = 0
    let output = ""
    for (let i = 0, j = s.length - 1; i < j; i++, j--) {
        if (s[i] < s[j]) {
            output += s[i]
        } else {
            output += s[j]
        }
    }
    const r = Array.from(output)
    r.reverse()
    if (s.length % 2 == 0) {
        return output + r.join("")
    } else {
        return output + s[Math.floor(s.length / 2)] + r.join("")
    }
};