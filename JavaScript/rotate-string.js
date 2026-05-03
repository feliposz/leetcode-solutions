/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function (s, goal) {
    if (s.length != goal.length) return false
    for (let shift = 0; shift < s.length; shift++) {
        let equals = true
        for (let i = 0; i < s.length; i++) {
            const j = (i + shift) % s.length
            if (s[i] !== goal[j]) {
                equals = false
                break
            }
        }
        if (equals) {
            return true
        }
    }
    return false
};