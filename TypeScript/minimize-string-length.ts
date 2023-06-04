function minimizedStringLength(s: string): number {
    const letters = {}
    for (const c of s) {
        letters[c] = 1
    }
    return Object.keys(letters).length
};