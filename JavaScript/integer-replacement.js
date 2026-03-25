/**
 * @param {number} n
 * @return {number}
 */
var integerReplacement = function (n) {
    let count = 0
    while (n > 1) {
        if (n === 3) {
            n--
        } else if (n % 2 == 0) {
            n /= 2
        } else if (n % 4 == 1) {
            n--
        } else {
            n++
        }
        count++
    }
    return count
};

var integerReplacement_SLOW = function (n) {
    if (n === 1) {
        return 0
    }
    if (n & 1) {
        return 1 + Math.min(integerReplacement(n + 1), integerReplacement(n - 1))
    }
    return 1 + integerReplacement(n / 2)
};
