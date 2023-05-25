function chunk(arr: any[], size: number): any[][] {
    const n: number = arr.length
    const ans: any[][] = []
    for (let i = 0; i < n; i += size) {
        const chunk: any[] = []
        for (let j = i; j < n && j < i + size; j++) {
            chunk.push(arr[j])
        }
        ans.push(chunk)
    }
    return ans
};