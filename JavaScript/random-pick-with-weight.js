/**
 * @param {number[]} w
 */
var Solution = function(w) {
    this.acc = []
    let total = 0
    for (let x of w) {
        total += x
        this.acc.push(total)
    }
    this.total = total
};

/**
 * @return {number}
 */
Solution.prototype.pickIndex = function() {
    let lo = 0
    let hi = this.acc.length - 1
    let i = -1
    const pick = Math.floor(Math.random() * this.total)
    while (lo < hi) {
        const mid = Math.floor((lo + hi) / 2)
        if (pick >= this.acc[mid]) {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    return lo
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(w)
 * var param_1 = obj.pickIndex()
 */