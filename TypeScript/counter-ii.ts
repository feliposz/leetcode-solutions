type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let current: number = init
    const obj: ReturnObj = {
        increment: (): number => {
            return ++current
        },
        decrement: (): number => {
            return --current
        },
        reset: (): number => {
            return current = init
        },
    }
    return obj
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */