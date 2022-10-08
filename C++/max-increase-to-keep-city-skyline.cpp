class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sz = grid.size();
        vector<int> maxV(sz);
        vector<int> maxH(sz);
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (grid[i][j] > maxV[i]) {
                    maxV[i] = grid[i][j];
                }
                if (grid[i][j] > maxH[j]) {
                    maxH[j] = grid[i][j];
                }
            }
        }
        
        int increase = 0;
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                int max = maxV[i] < maxH[j] ? maxV[i] : maxH[j];
                if (grid[i][j] < max) {
                    increase += max - grid[i][j];
                }
            }
        }
    
        return increase;
    }
};