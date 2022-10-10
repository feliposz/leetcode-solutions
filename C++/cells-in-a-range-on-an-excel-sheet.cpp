class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char c = s[0]; c <= s[3]; c++) {
            for (char r = s[1]; r <= s[4]; r++) {
                string cell;
                cell += c;
                cell += r;
                ans.push_back(cell);
            }
        }
        return ans;
    }
};