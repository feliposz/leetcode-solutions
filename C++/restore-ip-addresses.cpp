class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restore(s, 0, s.size(), 0, "", result);
        return result;
    }

    void restore(string &s, int i, int n, int dots, string tmp, vector<string> &result) {
        if (i == n && dots == 3) {
            result.push_back(tmp);
        } else if (i < n && dots < 3) {
            int part = 0;
            for (int len = 1; len <= 3; len++) {
                int digit = s[i + len - 1] - '0';
                part = part * 10 + digit;
                if (part < 256) {
                    restore(s, i + len, n, dots + (i > 0 ? 1 : 0), tmp + (i > 0 ? "." : "") + to_string(part), result);
                }
                if (part == 0 && len == 1) {
                    break;
                }
            }
        }
    }
};