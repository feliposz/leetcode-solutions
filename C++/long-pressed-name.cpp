class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        return isLongPressedName(name, typed, 0, 0, name.size(), typed.size());
    }
    
    bool isLongPressedName(string name, string typed, int i, int j, int m, int n) {
        if (i == m && j == n) {
            return true;
        } else if (i <= m && j <= n && name[i] == typed[j]) {
            return isLongPressedName(name, typed, i + 1, j + 1, m, n)
                || isLongPressedName(name, typed, i, j + 1, m, n);
        } else {
            return false;
        }
    }
};