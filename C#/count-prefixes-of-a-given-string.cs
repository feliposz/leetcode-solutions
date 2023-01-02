public class Solution {
    public int CountPrefixes(string[] words, string s) {
        int count = 0;
        foreach (var word in words) {
            if (s.StartsWith(word)) {
                count++;
            }
        }
        return count;
    }
}