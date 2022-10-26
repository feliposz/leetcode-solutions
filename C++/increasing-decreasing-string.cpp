class Solution {
public:
    string sortString(string s) {
        
        map<char,int> freq;
        for (char c: s) {
            freq[c]++;
        }
        
        string t;
        
        bool done = true;
        
        do {
            done = true;
            
            for (auto &p: freq) {
                if (p.second > 0) {
                    p.second--;
                    t.push_back(p.first);
                    done = false;
                }
            }
            
            for (auto it = freq.rbegin(); it != freq.rend(); it++) {
                if (it->second > 0) {
                    it->second--;
                    t.push_back(it->first);
                    done = false;
                }
            }
        } while (!done);
        
        return t;
    }
};