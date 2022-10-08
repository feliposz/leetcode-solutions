class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int b = 2; b <= n - 2; b++) {
            vector<int> s = toBase(n, b);
            if (!isPalindrome(s)) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> toBase(int n, int b) {
        vector<int> result;
        
        while (n) {
            result.push_back(n % b);
            n /= b;
        }
        
        return result;
    }
    
    bool isPalindrome(vector<int> &num) {
        int i = 0, j = num.size() - 1;
        while (i < j) {
            if (num[i++] != num[j--]) {
                return false;
            }
        }
        return true;
    }
};