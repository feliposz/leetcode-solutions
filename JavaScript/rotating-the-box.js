/**
 * @param {character[][]} boxGrid
 * @return {character[][]}
 */
var rotateTheBox = function (boxGrid) {
    const m = boxGrid.length
    const n = boxGrid[0].length
    const r = Array(n).fill(null)
    for (let i in r) {
        r[i] = Array(m).fill(null)
        for (let j in r[i]) {
            r[i][m-j-1] = boxGrid[j][i]
        }
    }
    for (let j in r[0]) {
        let moved = true
        do {
            moved = false
            for (let i = n - 1; i > 0; i--) {
                if (r[i][j] === '.' && r[i-1][j] === '#') {
                    r[i][j] = '#'
                    r[i-1][j] = '.'
                    moved = true
                }
            }
        } while (moved)
    }
    //console.table(r)
    return r
};