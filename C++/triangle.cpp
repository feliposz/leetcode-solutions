class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> tmp = triangle;
        int sz = triangle.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j <= i; j++) {
                if (i > 0) {
                    if (j == 0) {
                        tmp[i][j] += tmp[i-1][j];
                    } else if (j == i) {
                        tmp[i][j] += tmp[i-1][j-1];
                    } else {
                        tmp[i][j] += min(tmp[i-1][j], tmp[i-1][j-1]);
                    }
                }
            }            
        }
        return *min_element(tmp.back().begin(), tmp.back().end());
    }
};