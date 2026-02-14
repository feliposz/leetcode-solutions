/**
 * @param {number} x
 * @param {number} y
 * @return {string}
 */
var winningPlayer = function(x, y) {
    let winner = 1
    while (x >= 1 && y >= 4) {
        x -= 1
        y -= 4
        winner = 1 - winner
    }
    return ["Alice", "Bob"][winner]
};