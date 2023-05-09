function spiralOrder(matrix: number[][]): number[] {
    const result: number[] = []
    const m = matrix.length
    const n = matrix[0].length
    let top = 0
    let bottom = m - 1
    let left = 0
    let right = n - 1
    while(top < bottom && left < right) {
        for (let col = left; col <= right; col++) {
            result.push(matrix[top][col])
        }
        //console.log("A", result)
        top++
        for (let row = top; row <= bottom; row++) {
            result.push(matrix[row][right])
        }
        //console.log("B", result)
        right--
        for (let col = right; col >= left; col--) {
            result.push(matrix[bottom][col])
        }
        //console.log("C", result)
        bottom--
        for (let row = bottom; row >= top; row--) {
            result.push(matrix[row][left])
        }
        //console.log("D", result)
        left++
    }
    if (top == bottom) {
        for (let col = left; col <= right; col++) {
            result.push(matrix[top][col])
        }
    } else if (left == right) {
        for (let row = top; row <= bottom; row++) {
            result.push(matrix[row][right])
        }        
    }
    //console.log(top, bottom, left, right)
    return result
};