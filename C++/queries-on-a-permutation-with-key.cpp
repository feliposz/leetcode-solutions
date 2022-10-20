class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        for (int i = 1; i <= m; i++) {
            p.push_back(i);
        }
        
        vector<int> ans;
        
        int sz = p.size();
        
        for (int q: queries) {
            auto it = find(p.begin(), p.end(), q);
            ans.push_back(it - p.begin());
            p.erase(it);
            p.insert(p.begin(), q);            
        }
        
        return ans;
    }
};