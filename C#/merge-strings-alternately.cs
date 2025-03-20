public class Solution {
    public string MergeAlternately(string word1, string word2) {
        int i = 0, j = 0, k = 0;
        var sb = new char[word1.Length + word2.Length];
        while (i < word1.Length && j < word2.Length) {
            sb[k++] = word1[i++];
            sb[k++] = word2[j++];
        }
        while (i < word1.Length) {
            sb[k++] = word1[i++];
        }
        while (j < word2.Length) {
            sb[k++] = word2[j++];
        }
        return new string(sb);
    }
}