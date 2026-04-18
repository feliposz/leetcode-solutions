/**
 * @param {number} n
 * @return {number}
 */
var mirrorDistance = function(n) {
    const r = reverse(n)
    return Math.abs(n - r)
};

var reverse = function(x) {
    let y = 0
    while (x > 0) {
        y = (y * 10) + x % 10
        x = Math.trunc(x / 10)
    }
    return y
}