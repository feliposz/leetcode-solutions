/**
 * @param {string[]} words
 * @param {string} target
 * @param {number} startIndex
 * @return {number}
 */
var closestTarget = function (words, target, startIndex) {
    for (let dist = 0; dist < words.length; dist++) {
        const right = (startIndex + dist) % words.length
        const left = (startIndex + words.length - dist) % words.length
        if (words[right] === target) {
            return dist
        } else if (words[left] === target) {
            return dist
        }
    }
    return -1
};
