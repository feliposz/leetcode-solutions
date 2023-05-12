/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    const cache = {}
    const solve = function (i) {
        if (i >= questions.length)
            return 0
        if (cache[i] == undefined) { 
            const solved = questions[i][0] + solve(i + 1 + questions[i][1])
            const skipped = solve(i + 1)
            cache[i] = Math.max(solved, skipped)
        }
        return cache[i]
    }
    return solve(0)
};