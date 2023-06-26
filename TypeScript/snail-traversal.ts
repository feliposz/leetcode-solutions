declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    const n = this.length
    if (rowsCount * colsCount !== n) {
        return []
    }
    let ans: number[][] = Array(rowsCount)
    for (let row = 0; row < rowsCount; row++) {
        ans[row] = Array(colsCount).fill(0)
    }
    let index = 0
    for (let col = 0; col < colsCount; col++) {
        if (col % 2 === 0) {
            for (let row = 0; row < rowsCount; row++) {
                ans[row][col] = this[index++]
            }
        } else {
            for (let row = rowsCount - 1; row >= 0; row--) {
                ans[row][col] = this[index++]
            }
        }
    }
    return ans
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */