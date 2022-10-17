class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> people;
        int sz = names.size();
        for (int i = 0; i < sz; i++) {
            people[-heights[i]] = names[i];
        }
        vector<string> ans;
        for (auto it: people) {
            ans.push_back(it.second);
        }
        return ans;
    }
};