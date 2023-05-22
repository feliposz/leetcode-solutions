/**
 * @param {number} n
 * @return {number}
 */
var punishmentNumber = function(n) {
    let p = 0
    for (let i = 1; i <= n; i++) {
        const i2 = i * i
        if (checkPartitions("" + i2, i)) {
            p += i2
        }
    }
    return p
};

var checkPartitions = function (s, n) {
    if (n == 0) {
        return s.length == 0 || parseInt(s) == 0
    }
    for (let len = 1; len <= s.length; len++) {
        const p = parseInt(s.substr(0, len))
        if (p <= n && checkPartitions(s.substr(len), n - p)) {
            return true
        }
    }
    return false
}
