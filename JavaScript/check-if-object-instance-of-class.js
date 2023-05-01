/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj == null || obj == undefined || typeof classFunction != 'function')
        return false
    if (classFunction == Object)
        return true
    return obj.constructor == classFunction || obj instanceof classFunction
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */