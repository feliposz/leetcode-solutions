class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> total;
        
        for (vector<int> &log: logs) {
            total[log[0]].insert(log[1]);
        }
        
        vector<int> ans(k);
        
        for (auto &t: total) {
            int uam = t.second.size();
            ans[uam-1]++;
        }
        
        return ans;
    }
};