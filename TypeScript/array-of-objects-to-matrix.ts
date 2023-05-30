function jsonToMatrix(arr: any[]): (string | number | boolean | null)[] {
    const ans = []
    const keys = {}
    const data = []
    for (const obj of arr) {
        const flattened = flatObj(obj)
        data.push(flattened)
        for (const key in flattened) {
            keys[key] = 1
        }
    }
    const sortedKeys = Object.keys(keys).sort()
    ans.push(sortedKeys)
    for (const obj of data) {
        const row = []
        for (const key of sortedKeys) {
            if (key in obj) {
                row.push(obj[key])
            } else {
                row.push("")
            }
        }
        ans.push(row)
    }
    return ans
};

function flatObj(obj: any) {
    const ans = {}
    for (const key in obj) {
        switch (typeof obj[key]) {
            case 'number':
            case 'boolean':
            case 'string':
                ans[key] = obj[key]
                break
            default:
                if (obj[key] == null) {
                    ans[key] = null
                } else {
                    const subObj = flatObj(obj[key])
                    for (const sub in subObj) {
                        ans[key + '.' + sub] = subObj[sub]
                    }
                }
                break
        }
    }
    return ans
}