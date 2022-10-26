class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> freq;
        int prev = -1;
        for (char c: s) {
            freq[c]++;
            prev = freq[c];
        }
        
        for (auto p: freq) {
            if (p.second != prev) {
                return false;
            }
            prev = p.second;
        }
        
        return true;
    }
};