type F = (...args: any[]) => void

function throttle(fn: F, t: number): F {
    let intervalId = null
    let savedArgs = null
    return function (...args) {
        if (intervalId === null) {
            fn(...args)
            intervalId = setInterval(() => {
                if (savedArgs) {
                    fn(...savedArgs)
                    savedArgs = null
                } else {
                    clearInterval(intervalId)
                    intervalId = null
                }
            }, t)
        } else {
            savedArgs = args
        }
    }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */