function join(arr1: any[], arr2: any[]): any[] {
    const merge = {}
    for (const obj of arr1) {
        merge[obj.id] = obj
    }
    for (const obj of arr2) {
        if (obj.id in merge) {
            Object.assign(merge[obj.id], obj)
        } else {
            merge[obj.id] = obj
        }
    }
    return Object.values(merge)
};