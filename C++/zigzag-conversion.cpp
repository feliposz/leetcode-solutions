class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        
        if (numRows == 1) {
            return s;
        }
        
        for (int i = 0; i < numRows; i++) {
            rows[i] = string(s.size(), ' ');
        }
        
        bool zigzag = true;
        int r = 0;
        int c = 0;
        for (char ch: s) {
            rows[r][c] = ch;
            if (zigzag) {                
                if (r == numRows - 1) {
                    zigzag = false;
                    r--;
                    c++;
                } else {
                    r++;
                }
            } else {
                if (r == 0) {
                    zigzag = true;
                    r++;
                } else {
                    c++;
                    r--;
                }
            }
        }
        
        string t;
        for (string &row: rows) {
            for (char ch: row) {
                if (ch != ' ') {
                    t += ch;
                }
            }
        }
        
        return t;
    }
};