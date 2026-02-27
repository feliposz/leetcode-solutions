/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number}
 */
var matrixSumQueries = function (n, queries) {
    const seenRows = new Set()
    const seenCols = new Set()
    let total = 0
    for (let i = queries.length - 1; i >= 0; i--) {
        const [type, index, val] = queries[i]
        if (type == 0) {
            if (!seenRows.has(index)) {
                seenRows.add(index)
                total += val * (n - seenCols.size)
            }
        } else {
            if (!seenCols.has(index)) {
                seenCols.add(index)
                total += val * (n - seenRows.size)
            }
        }
        if (n === seenRows.size || n === seenCols.size) {
            break
        }
    }
    return total
};