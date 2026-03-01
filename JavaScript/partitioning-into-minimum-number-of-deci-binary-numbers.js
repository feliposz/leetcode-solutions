/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    const d = n.split('')
    d.sort()
    return Number(d[d.length-1])
};