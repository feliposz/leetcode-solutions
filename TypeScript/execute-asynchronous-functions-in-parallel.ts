async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    const n = functions.length
    const ans = Array(n)
    let countDown = n
    return new Promise((resolve, reject) => {
        for (let i = 0; i < n; i++) {
            functions[i]().then((res) => {
                ans[i] = res
                countDown--
                if (countDown === 0) {
                    resolve(ans)
                }
            }).catch((err) => {
                reject(err)
            })
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */