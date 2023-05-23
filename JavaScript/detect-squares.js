var DetectSquares = function() {
    this.rows = {}
};

/** 
 * @param {number[]} point
 * @return {void}
 */
DetectSquares.prototype.add = function(point) {
    const [x, y] = point
    if (!(y in this.rows)) {
        this.rows[y] = {}
    }
    if (!(x in this.rows[y])) {
        this.rows[y][x] = 0
    }
    this.rows[y][x]++
};

/** 
 * @param {number[]} point
 * @return {number}
 */
DetectSquares.prototype.count = function(point) {
    const [x1, y1] = point
    let count = 0
    for (const x2 in this.rows[y1]) {
        const dx = Math.abs(x1 - parseInt(x2, 10))
        if (dx > 0) {
            for (const y2 of [y1 - dx, y1 + dx]) {
                if (y2 in this.rows && x1 in this.rows[y2] && x2 in this.rows[y2]) {
                    count += this.rows[y1][x2] * this.rows[y2][x2] * this.rows[y2][x1]                    
                }
            }
        }
    }
    return count
};

/** 
 * Your DetectSquares object will be instantiated and called as such:
 * var obj = new DetectSquares()
 * obj.add(point)
 * var param_2 = obj.count(point)
 */