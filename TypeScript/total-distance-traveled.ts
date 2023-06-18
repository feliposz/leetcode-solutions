function distanceTraveled(mainTank: number, additionalTank: number): number {
    let distance = 0
    const kmPerLiter = 10
    while (mainTank >= 5 && additionalTank >= 1) {
        mainTank -= 5
        mainTank++
        additionalTank--
        distance += 5 * kmPerLiter 
    }
    if (mainTank > 0) {
        distance += mainTank * kmPerLiter
    }
    return distance
};