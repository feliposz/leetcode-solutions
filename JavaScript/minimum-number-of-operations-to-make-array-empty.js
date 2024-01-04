/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    var ncount = {}
    for (n of nums) {
        ncount[n] = (n in ncount) ? ncount[n] + 1 : 1
    }
    //console.log(ncount)
    var ops = 0
    for (k in ncount) {
        var count = ncount[k]
        //console.log(k, count)
        if (count === 1 ){
            return -1
        }
        if ((count % 3) === 0) {
            ops += count / 3
        } else {
            ops += Math.floor(count / 3) + 1
        }
    }
    return ops
};