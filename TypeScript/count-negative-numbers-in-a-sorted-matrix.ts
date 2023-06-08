function countNegatives(grid: number[][]): number {
    const m = grid.length
    const n = grid[0].length
    let count = 0
    for (let row = 0; row < m; row++) {
        //console.log(grid[row])
        let left = 0, right = n - 1
        if (grid[row][left] < 0) {
            count += n
        } else if (grid[row][right] >= 0) {
            // no negative numbers in this row
        } else {
            while (left < right) {
                const col = Math.floor((left + right) / 2)
                if (grid[row][col] >= 0) {
                    left = col + 1
                } else {
                    right = col
                }
            }
            //console.log("First negative index is ", right, "value", grid[row][right], "count of negatives", n - right)
            count += n - right
        }
    }
    return count
};