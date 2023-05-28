declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn) {
    const result = {}
    for (let i = 0; i < this.length; i++) {
        const k = fn(this[i])
        if (result[k] === undefined) {
            result[k] = []
        }
        result[k].push(this[i])
    }
    return result
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */