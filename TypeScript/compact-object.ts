type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
    if (obj instanceof Array) {
        const ans = []
        for (const x of obj) {
            if (x) {
                const y = compactObject(x)
                if (y) {
                    ans.push(y)
                }
            }
        }
        return ans
    }
    if (obj) {
        if (obj instanceof Object) {
            const ans = {}
            for (const k in obj) {
                if (obj[k]) {
                    const y = compactObject(obj[k])
                    if (y) {
                        ans[k] = y
                    }
                }
            }
            return ans
        }
    }
    return obj
};