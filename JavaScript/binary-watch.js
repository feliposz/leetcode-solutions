/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var readBinaryWatch = function(turnedOn) {
    const bitCount = Array(60)
    const result = []
    for (let m = 0; m < 60; m++) {
        bitCount[m] = ((m & 32) >> 5) + ((m & 16) >> 4) + ((m & 8) >> 3) +
            ((m & 4) >> 2) + ((m & 2) >> 1) + (m & 1)
    }
    //console.table(bitCount)
    for (let m = 0; m < 60; m++) {
        if (bitCount[m] > turnedOn) {
            continue
        }
        for (let h = 0; h < 12; h++) {
            if (bitCount[m] + bitCount[h] === turnedOn) {
                result.push(h + ':' + (m < 10 ? '0' : '') + m)
            }
        }
    }
    return result
};