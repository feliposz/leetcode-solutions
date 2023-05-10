/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    const ans = new Array(n)
    const lastNum = n * n

    for (let i = 0; i < n; i++) {
        ans[i] = new Array(n).fill(0)
    }
    
    // left, down, right, up
    const dirVectors = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    let x = 1, d = 0, i = 0, j = 0

    while (x <= lastNum) {
        // check collision with borders or other numbers
        if ( i < 0 || j < 0 || i >= n || j >= n || ans[i][j] != 0) {
            // go back
            i -= dirVectors[d][0]
            j -= dirVectors[d][1]

            // turn to the next direction
            d = (d + 1) % 4

            // advance in new direction
            i += dirVectors[d][0]
            j += dirVectors[d][1]
        }

        ans[i][j] = x++
        i += dirVectors[d][0]
        j += dirVectors[d][1]
    }

    return ans
};