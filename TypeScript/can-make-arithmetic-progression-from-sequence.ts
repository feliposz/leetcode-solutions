function canMakeArithmeticProgression(arr: number[]): boolean {
    arr.sort((a, b) => a - b)
    const delta = arr[0] - arr[1]
    for (let i = 2; i < arr.length; i++) {
        if (arr[i-1] - arr[i] !== delta) {
            return false
        }
    }
    return true
};