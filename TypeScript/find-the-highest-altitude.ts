function largestAltitude(gain: number[]): number {
    let altitude = 0
    let highest = 0
    for (let i = 0; i < gain.length; i++) {
        altitude += gain[i]
        if (highest < altitude) {
            highest = altitude
        }
    }
    return highest
};