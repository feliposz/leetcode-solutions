/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_glass
 * @return {number}
 */
var champagneTower = function(poured, query_row, query_glass) {
    const tower = Array(100)
    for (let row = 0; row < 100; row++) {
        tower[row] = Array(row+1)
        for (let glass = 0; glass <= row; glass++) {
            tower[row][glass] = 0
        }
    }
    tower[0][0] = poured
    let finished = false
    for (let row = 0; row < 100-1 && !finished; row++) {
        finished = true
        for (let glass = 0; glass <= row; glass++) {
            if (tower[row][glass] > 1) {
                const excess = tower[row][glass] - 1
                tower[row][glass] = 1
                tower[row+1][glass] += excess / 2
                tower[row+1][glass+1] += excess / 2
                finished = false
            }
        }
        //console.log((row + 1) + ': ' + tower[row].join('\t'))
    }

    return tower[query_row][query_glass]
};