/**
 * @param {number} num
 * @return {boolean}
 */
var sumOfNumberAndReverse = function(num) {
    for (let n = 0; n <= num; n++) {
        if (num === (n + reverse(n))) {
            return true
        }
    }
    return false
};

var reverse = function(num) {
    let result = 0
    while (num > 0) {
        result = result * 10 + num % 10
        num = Math.floor(num / 10)
    }
    return result
}