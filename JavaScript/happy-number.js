/**
 * @param {number} n
 * @return {boolean}
 */

var getNext = function(n) {
    let tmp = n;
    let result = 0;
    while (tmp > 0) {
        let digit = tmp % 10;
        result += digit * digit;
        tmp = Math.floor(tmp / 10);
    }
    return result;
};

var isHappy = function(n) {
    let visited = {};
    while (n != 1 && !(n in visited)) {
        visited[n] = 1;
        n = getNext(n);
    }
    return n == 1;
};