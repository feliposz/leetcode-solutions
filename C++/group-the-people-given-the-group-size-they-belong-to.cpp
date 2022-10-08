class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> grp;
        
        int sz = groupSizes.size();
        
        for (int id = 0; id < sz; id++) {
            int groupSize = groupSizes[id];
            grp[groupSize].push_back(id);
        }
        
        vector<vector<int>> result;
        
        vector<int> current;
            
        for (auto &it: grp) {
            for (auto id: it.second) {
                current.push_back(id);
                if (current.size() == it.first) {
                    result.push_back(current);
                    current.clear();
                }
            }
        }
        
        return result;
    }
};