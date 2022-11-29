class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int,int>> m;
        
        int sz = s.size();
        
        for (int i = 0; i < sz; i++) {
            char c = s[i];
            if (m.count(c) == 0) {
                m[c].first = m[c].second = i;
            } else {
                m[c].second = i;
            }
        }
        
        vector<pair<int,int>> v;
        
        for (auto &p: m) {
            v.push_back(p.second);
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 1; i < v.size(); i++) {
            int start1 = v[i-1].first;
            int end1 = v[i-1].second;
            int start2 = v[i].first;
            int end2 = v[i].second;
            
            if ((start2 >= start1) && (start2 <= end1)) {
                if (end1 < end2) {
                    v[i-1].second = v[i].second;
                }
                v.erase(v.begin() + i);
                i--;
            }
        }
        
        vector<int> ans;
        for (auto &p: v) {
            ans.push_back(p.second - p.first + 1);
        }
        return ans;
    }
};