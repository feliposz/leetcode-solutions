class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> soldiers(mat.size());

        for (int i = 0; i < mat.size(); i++)
        {
            soldiers[i] = { 0, i };
            for (int j = 0; j < mat[i].size(); j++)
            {
                soldiers[i].first += mat[i][j];
            }
        }

        sort(soldiers.begin(), soldiers.end());

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(soldiers[i].second);
        }

        return result;
    }
};