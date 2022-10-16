class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2);
        for (int i = 0; i < n-2; i++) {
            ans[i].resize(n-2);
        }
        for (int i = 1; i < n - 1; i++) {            
            for (int j = 1; j < n - 1; j++) {
                int max = grid[i-1][j-1];
                for (int i2 = -1; i2 <= 1; i2++) {
                    for (int j2 = -1; j2 <= 1; j2++) {
                        if (grid[i+i2][j+j2] > max) {
                            max = grid[i+i2][j+j2];
                        }
                    }
                }
                ans[i-1][j-1] = max;
            }
        }
        return ans;
    }
};