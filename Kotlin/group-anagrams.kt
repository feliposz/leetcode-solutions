class Solution {
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        // define map of lists to contain anagrams
        var m = HashMap<String, ArrayList<String>>()

        // loop through strs
        for (s in strs) {
            // split string into char array and sort chars
            var tmp = s.toCharArray();
            tmp.sort()

            // use sorted str as key and add str to list at given bucket
            var k = tmp.joinToString(separator = "")
            if (m[k] == null) {
                m[k] = ArrayList<String>()
            }
            m[k]?.add(s)
        }

        var result = ArrayList<List<String>>()
        // loop over map appending each generated list to result
        for ((k, v) in m) {
            result.add(v.toList())
        }

        // convert tolist
        return result.toList()
    }
}