class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> hist;
        
        for (char c: s) {
            hist[c]++;
        }
        
        for (char c: t) {
            hist[c]--;
        }
        
        int steps = 0;
        for (auto p: hist) {
            steps += max(0, p.second);
        }
        return steps;
    }
};