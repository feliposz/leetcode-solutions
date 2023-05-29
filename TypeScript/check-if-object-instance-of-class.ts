function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (obj === null || obj === undefined || typeof classFunction !== 'function')
        return false
    if (classFunction === Object)
        return true
    return obj.constructor === classFunction || obj instanceof classFunction
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */