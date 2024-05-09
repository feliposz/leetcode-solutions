function maximumHappinessSum(happiness: number[], k: number): number {
    happiness.sort((a, b) => b - a);
    let total = 0;
    for (let i = 0; i < happiness.length && i < k; i++) {
        total += Math.max(0, happiness[i] - i);
    }
    return total;
};
