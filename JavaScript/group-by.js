/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let g = {}
    for (const n of this) {
        const k = fn(n)
        if (!(k in g))
            g[k] = []
        g[k].push(n)
    }
    return g
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */