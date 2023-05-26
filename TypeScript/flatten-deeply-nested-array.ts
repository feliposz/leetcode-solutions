type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if (n == 0) {
        return arr
    }
    const result: MultiDimensionalArray = []
    for (const elem of arr) {
        if (typeof elem == 'number') {
            result.push(elem)
        } else {
            Array.prototype.push.apply(result, flat(elem, n - 1))
        }
    }
    return result
};