class FrequencyTracker() {

    val values = HashMap<Int, Int>().withDefault { 0 }
    val freq = HashMap<Int, Int>().withDefault { 0 }

    fun add(number: Int) {
        values[number] = values.getValue(number) + 1
        val f = values.getValue(number)
        freq[f - 1] = maxOf(0, freq.getValue(f - 1) - 1)
        freq[f] = freq.getValue(f) + 1
    }

    fun deleteOne(number: Int) {
        if (values.contains(number)) {
            val f = values.getValue(number)
            freq[f - 1] = freq.getValue(f - 1) + 1
            freq[f] = maxOf(0, freq.getValue(f) - 1)
            values[number] = maxOf(0, values.getValue(number) - 1)
        }
    }

    fun hasFrequency(frequency: Int): Boolean {
        return freq.getValue(frequency) > 0
    }

}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * var obj = FrequencyTracker()
 * obj.add(number)
 * obj.deleteOne(number)
 * var param_3 = obj.hasFrequency(frequency)
 */