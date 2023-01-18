class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = rows > 0 ? grid[0].size() : 0;
        
        int islands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    paintGrid(grid, i, j, rows, cols);
                }
            }
        }
        return islands;
    }
    
    void paintGrid(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            if (i > 0) paintGrid(grid, i - 1, j, rows, cols);
            if (j > 0) paintGrid(grid, i, j - 1, rows, cols);
            if (i < rows - 1) paintGrid(grid, i + 1, j, rows, cols);
            if (j < cols - 1) paintGrid(grid, i, j + 1, rows, cols);
        }
    }
};