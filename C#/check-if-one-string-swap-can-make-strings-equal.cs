public class Solution {
    public bool AreAlmostEqual(string s1, string s2) {
        if (s1.Length != s2.Length) {
            return false;
        }
        int a = -1, b = -1;
        for (int i = 0; i < s1.Length; i++) {
            if (s1[i] != s2[i]) {
                if (a == -1) {
                    a = i;
                } else if (b == -1) {
                    b = i;
                } else {
                    return false;
                }
            }
        }
        if (a == -1) {
            return true;
        }
        if (b == -1) {
            return false;
        }
        return s1[a] == s2[b] && s1[b] == s2[a];
    }
}