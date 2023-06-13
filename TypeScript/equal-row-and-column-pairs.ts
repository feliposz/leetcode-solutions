function equalPairs(grid: number[][]): number {
    const n = grid.length
    let count = 0
    for (let row = 0; row < n; row++) {
        for (let col = 0; col < n; col++) {
            let equal = true
            for (let index = 0; index < n; index++) {
                if (grid[row][index] !== grid[index][col]) {
                    equal = false
                    break
                }
            }
            if (equal) {
                count++
            }
        }
    }
    return count
};