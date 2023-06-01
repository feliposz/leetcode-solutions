function objDiff(obj1: any, obj2: any): any {
    const result = helper(obj1, obj2)
    return result === null ? {} : result
};

function helper(obj1: any, obj2: any): any {
    if (obj1 === obj2) {
        return null
    }
    if ((typeof obj1 === 'object' && typeof obj2 === 'object') &&
        (obj1 !== null && obj2 !== null) &&
        (obj1 instanceof Array === obj2 instanceof Array)) {
        const result = {}
        for (const k in obj1) {
            if (k in obj2) {
                const diff = helper(obj1[k], obj2[k])
                if (diff !== null) {
                    result[k] = diff
                }
            }
        }
        if (Object.keys(result).length === 0) {
            return null
        }
        return result
    }
    return [obj1, obj2]
}