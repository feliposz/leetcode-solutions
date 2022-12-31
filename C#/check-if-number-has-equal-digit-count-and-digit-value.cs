public class Solution {
    public bool DigitCount(string num) {
        var count = new int[10];
        foreach (char c in num) {
            count[c - '0']++;
        }
        for (int i = 0; i < num.Length; i++) {
            if (num[i] - '0' != count[i]) {
                return false;
            }
        }
        return true;
    }
}