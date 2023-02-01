class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int i = m - 1;
        int j = 0;
        while ((i >= 0) && (j < n)) {
            if (grid[i][j] < 0) {
                i--;
                count += n - j;
            } else {
                j++;
            }            
        }
        return count;
    }
};