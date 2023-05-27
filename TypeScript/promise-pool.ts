type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
    return new Promise((resolve, reject) => {
        if (functions.length == 0) {
            resolve(0)
        }

        let index = 0
        let inProgress = 0
        const completed = (result) => {
            inProgress--
            if (index < functions.length ) {
                inProgress++
                functions[index++]().then(completed).catch(reject)
            } else if (inProgress == 0) {
                resolve(0)
            }
        }

        while (index < n && index < functions.length) {
            inProgress++
            functions[index++]().then(completed).catch(reject)
        }
    })
}

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */