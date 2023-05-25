type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    const memo = new Map()
    return function(...args) {
        if (args in memo) {
            return memo[args]
        }
        return memo[args] = fn(...args)
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */