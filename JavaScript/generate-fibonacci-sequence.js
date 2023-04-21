/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    yield 0
    let a = 0
    let b = 1
    while (true) {
        [a, b] = [b, a + b]
        yield a
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */