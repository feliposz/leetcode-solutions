class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r <= rows; r++) {
            int left = 0;
            for (int c = 0; c <= cols; c++) {
                int curr = (c < cols && r < rows) ? grid[r][c] : 0;
                int up = (c < cols && r > 0) ? grid[r - 1][c] : 0;
                perimeter += (curr != up) + (curr != left);
                left = curr;
            }
        }
        return perimeter;
    }
};