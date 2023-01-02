public class Solution {
    public bool DetectCapitalUse(string word) {
        int countUpper = 0;
        int countLower = 0;
        if (Char.IsUpper(word[0])) {
            for (int i = 1; i < word.Length; i++) {
                if (Char.IsUpper(word[i])) {
                    countUpper++;
                } else {
                    countLower++;
                }
            }
            return !(countLower != 0 && countUpper != 0);
        } else {
            for (int i = 1; i < word.Length; i++) {
                if (Char.IsUpper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
}