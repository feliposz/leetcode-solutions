class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        int count = 0;
        if (x >= y) {
            count = removeAndCount(s, "ab");
            points += x * count;
            count = removeAndCount(s, "ba");
            points += y * count;
        } else {
            count = removeAndCount(s, "ba");
            points += y * count;
            count = removeAndCount(s, "ab");
            points += x * count;
        }
        return points;
    }

    int removeAndCount(string& s, string sub) {
        int count = 0;
        vector<char> stack;
        int top = -1;
        for (auto c : s) {
            if (!stack.empty() && c == sub[1] && stack.back() == sub[0]) {
                count++;
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        string tmp(stack.begin(), stack.end());
        s = tmp;
        return count;
    }
};