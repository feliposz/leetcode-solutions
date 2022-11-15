class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int area = calcArea(grid, i, j, m, n);
                if (maxArea < area) {
                    maxArea = area;
                }
            }            
        }
        
        return maxArea;
    }
    
    int calcArea(vector<vector<int>>& grid, int i, int j, int m, int n) {
        int area = 0;
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            area = 1;
            if (i > 0) {
                area += calcArea(grid, i - 1, j, m, n);
            }
            if (i < m - 1) {
                area += calcArea(grid, i + 1, j, m, n);
            }
            if (j > 0) {
                area += calcArea(grid, i, j - 1, m, n);
            }
            if (j < n - 1) {
                area += calcArea(grid, i, j + 1, m, n);
            }            
        }
        return area;
    }
};