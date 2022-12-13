class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char c: s) {
            freq[c]++;
        }
        
        map<int, vector<char>> inv;
        for (auto p: freq) {
            inv[-p.second].push_back(p.first);
        }
        
        string t;
        for (auto p: inv) {
            for (auto c: p.second) {
                int count = -p.first;
                while (count--) {
                    t += c;
                }
            }
        }
        return t;
    }
};