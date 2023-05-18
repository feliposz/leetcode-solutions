/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findSmallestSetOfVertices = function(n, edges) {
    const incomingEdge = Array(n).fill(false)
    for (const [_, to] of edges) {
        incomingEdge[to] = true
    }
    const ans = []
    for (let i = 0; i < n; i++) {
        if (!incomingEdge[i]) {
            ans.push(i)
        }
    }
    return ans
};