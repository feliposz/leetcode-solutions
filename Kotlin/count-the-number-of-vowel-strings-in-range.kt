class Solution {
    fun vowelStrings(words: Array<String>, left: Int, right: Int): Int {
        var count = 0
        val vowels = "aeiou"
        for (i in left..right) {
            if (vowels.indexOf(words[i][0]) >= 0 && vowels.indexOf(words[i][words[i].length-1]) >= 0) {
                count++
            }
        }
        return count
    }
}