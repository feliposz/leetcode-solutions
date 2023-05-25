function areDeeplyEqual(o1: any, o2: any): boolean {
    
    // both should have same type
    if (typeof o1 !== typeof o2)
        return false

    // are both the same object?
    if (o1 === o2)
        return true

    // if both are arrays, check each element recursively
    if (o1 instanceof Array && o2 instanceof Array) {
        if (o1.length != o2.length)
            return false
        for (let i = 0; i < o1.length; i++)
            if (!areDeeplyEqual(o1[i], o2[i]))
                return false
        return true
    }

    // both need to be arrays
    if (o1 instanceof Array || o2 instanceof Array)
        return false

    // if both are objects, check if each property are equal
    if (o1 instanceof Object && o2 instanceof Object) {
        for (const prop in o1) {
            if (!(prop in o2))
                return false
            if (!areDeeplyEqual(o1[prop], o2[prop]))
                return false
        }
        // check if o2 has any properties that o1 didn't have
        for (const prop in o2)
            if (!(prop in o1))
                return false
        return true
    }

    return false
};