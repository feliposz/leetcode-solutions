function minFlips(a: number, b: number, c: number): number {
    let count = 0
    while (a || b || c) {
        if (c & 1) {
            if ((a & 1) == 0 && (b & 1) == 0) {
                count++
            }
        } else {
            if (a & 1) {
                count++
            } 
            if (b & 1) {
                count++
            }
        }
        a >>= 1
        b >>= 1
        c >>= 1
    }
    return count
};