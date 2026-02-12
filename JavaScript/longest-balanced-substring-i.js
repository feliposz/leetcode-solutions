/**
 * @param {string} s
 * @return {number}
 */
var longestBalanced = function(s) {
    let max = 0
    for (let i = 0; i < s.length; i++) {
        let d = Array(26).fill(0)
        for (let j = i; j < s.length; j++) {
            const c = s.charCodeAt(j) - 97 // 'a'
            d[c]++
            let balanced = true
            for (const y of d) {
                if (y > 0 && y !== d[c]) {
                    balanced = false
                    break
                }
            }
            if (balanced) {
                const length = j - i + 1
                max = max > length ? max : length
            }
        }
    }
    return max
};