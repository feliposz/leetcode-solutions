/**
 * @param {string[]} words
 * @return {string[][]}
 */
var wordSquares = function (words) {
    const result = []
    words.sort()
    for (let i = 0; i < words.length; i++) {
        const top = words[i]
        for (let j = 0; j < words.length; j++) {
            const left = words[j]
            if (j !== i && top[0] === left[0]) {
                for (let k = 0; k < words.length; k++) {
                    const right = words[k]
                    if (k !== i && k !== j && top[3] === right[0]) {
                        for (let l = 0; l < words.length; l++) {
                            const bottom = words[l]
                            if (l !== i && l !== j && l !== k &&
                                bottom[0] === left[3] &&
                                bottom[3] === right[3]) {
                                result.push([top, left, right, bottom])
                            }
                        }
                    }
                }
            }
        }
    }
    return result
};