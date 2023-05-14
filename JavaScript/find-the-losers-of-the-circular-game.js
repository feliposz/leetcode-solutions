/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var circularGameLosers = function(n, k) {
    const players = Array(n).fill(false)
    let curr = 0;
    for (let round = 1; players[curr] == false; round++) {
        players[curr] = true
        curr = (curr + round * k) % n
    }
    const ans = []
    for (let i = 0; i < n; i++) {
        if (!players[i]) {
            ans.push(i + 1)
        }
    }
    return ans
};