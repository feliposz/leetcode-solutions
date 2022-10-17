class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> test(allowed.begin(), allowed.end());
        
        int count = 0;
        for (string word: words) {
            bool ok = true;
            for (char c: word) {
                if (test.count(c) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};