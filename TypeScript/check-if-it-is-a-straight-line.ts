function checkStraightLine(coordinates: number[][]): boolean {
    const n = coordinates.length
    const dx = coordinates[0][0] - coordinates[1][0]
    const dy = coordinates[0][1] - coordinates[1][1]
    if (dy === 0) { // horizontal line
        for (let i = 1; i < n; i++) {
            const dy2 = coordinates[0][1] - coordinates[i][1]
            if (dy2 !== 0) {
                return false
            }
        }        
    } else {
        const slope = dx / dy
        for (let i = 1; i < n; i++) {
            const dx2 = coordinates[0][0] - coordinates[i][0]
            const dy2 = coordinates[0][1] - coordinates[i][1]
            const slope2 = dx2 / dy2
            if (dy2 === 0 || Math.abs(slope - slope2) > 0.0000001) { // floating-point tolerance
                return false
            }
        }        
    }
    return true
};