class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &w: words) {
            bool isPalindrome = true;
            for (int i = 0, j = w.length() - 1; i < j; i++, j--) {
                if (w[i] != w[j]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                return w;
            }
        }
        return "";
    }
};