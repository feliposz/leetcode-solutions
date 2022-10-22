class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int area = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    area += grid[i][j];
                } else {
                    area += abs(grid[i-1][j] - grid[i][j]);
                }
                if (i == n - 1) {
                    area += grid[i][j];
                }
                
                if (j == 0) {
                    area += grid[i][j];
                } else {
                    area += abs(grid[i][j-1] - grid[i][j]);
                }
                if (j == n - 1) {
                    area += grid[i][j];
                }
                
                if (grid[i][j]) {
                    area += 2;
                }
            }
        }
        
        return area;
    }
};