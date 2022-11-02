class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        s += (columnNumber - 1) % 26 + 'A';
        if (columnNumber > 26) {
            s = convertToTitle((columnNumber - 1)/26) + s;
        }
        return s;
    }
};