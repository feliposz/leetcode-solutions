class Solution {
public:   
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        
        set<int> from;
        set<int> to;
        
        for (auto e: edges) {
            from.insert(e[0]);
            to.insert(e[1]);
        }
        
        for (int f: from) {
            if (!to.count(f)) {
                ans.push_back(f);
            }
        }
        
        return ans;
    }
    
};