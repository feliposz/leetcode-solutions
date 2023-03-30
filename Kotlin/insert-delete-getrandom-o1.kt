class RandomizedSet() {

    val values = mutableSetOf<Int>()

    fun insert(`val`: Int): Boolean {
        return values.add(`val`)
    }

    fun remove(`val`: Int): Boolean {
        return values.remove(`val`)
    }

    fun getRandom(): Int {
        return values.random()
    }

}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */