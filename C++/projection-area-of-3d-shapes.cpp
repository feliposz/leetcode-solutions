class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<int> maxRows(n);
        vector<int> maxCols(n);
        
        int area = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maxRows[i] < grid[i][j]) {
                    maxRows[i] = grid[i][j];
                }
                if (maxCols[i] < grid[j][i]) {
                    maxCols[i] = grid[j][i];
                }
                if (grid[i][j]) {
                    area++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            area += maxRows[i] + maxCols[i];
        }
        
        return area;
    }
};