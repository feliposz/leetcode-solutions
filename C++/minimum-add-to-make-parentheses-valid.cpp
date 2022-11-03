class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, mustOpen = 0;
        for (char c: s) {
            switch(c) {
                case '(': balance++; break;
                case ')': balance--; break;
            }
            if (balance == -1) {
                balance = 0;
                mustOpen++;
            }
        }
        return mustOpen + balance;
    }
};