class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> temp;
        for (vector<int> &item: items1) {
            temp[item[0]] = item[1];
        }
        for (vector<int> &item: items2) {
            temp[item[0]] += item[1];
        }
        vector<vector<int>> result;
        for (auto &p: temp) {
            result.push_back({p.first, p.second});
        }
        return result;
    }
};