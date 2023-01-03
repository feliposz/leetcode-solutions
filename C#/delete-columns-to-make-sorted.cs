public class Solution {
    public int MinDeletionSize(string[] strs) {
        int count = 0;
        for (int j = 0; j < strs[0].Length; j++) {
            for (int i = 1; i < strs.Length; i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}