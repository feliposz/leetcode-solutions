class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int c = 0; c < n; c++) {
            for (int r = 1; r < m; r++) {
                if ((r + c < n) && (matrix[0][c] != matrix[r][r+c])) {
                    return false;
                }
            }
        }
        
        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n; c++) {
                if ((r + c < m) && (matrix[r][0] != matrix[r+c][c])) {
                    return false;
                }
            }
        }
        
        return true;
    }
};