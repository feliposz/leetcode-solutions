class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for (string &w: words) {
            freq[w]++;
        }
        
        map<int, vector<string>> mfreq;
        
        for (auto &p: freq) {
            mfreq[-p.second].push_back(p.first);
        }
        
        vector<string> ans;
        int n = 0;
        
        for (auto &p: mfreq) {
            for(auto &w: p.second) {
                n++;
                ans.push_back(w);
                if (n == k) {                    
                    return ans;
                }
            }
        }
        
        return ans;
    }
};