async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    return promise1.then((a) => promise2.then((b) => a + b))
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */