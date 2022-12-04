class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        if (digits.size() == 0) {
            return ans;
        } else if (digits.size() == 1) {
            int d = digits[0] - '0';
            for (char c: key[d]) {
                ans.push_back(string(1, c));
            }
        } else {
            int d = digits[0] - '0';
            for (char c: key[d]) {
                for (string s: letterCombinations(digits.substr(1))) {
                    ans.push_back(c + s);
                }                
            }
        }
        return ans;
    }
};