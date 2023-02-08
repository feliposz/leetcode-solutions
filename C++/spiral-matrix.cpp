class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int row1 = 0, row2 = matrix.size() - 1;
        int col1 = 0, col2 = matrix[0].size() - 1;
        
        while ((col1 < col2) && (row1 < row2)) {
            for (int c = col1; c < col2; c++) {
                ans.push_back(matrix[row1][c]);
            }
            for (int r = row1; r < row2; r++) {
                ans.push_back(matrix[r][col2]);
            }
            for (int c = col2; c > col1; c--) {
                ans.push_back(matrix[row2][c]);
            }
            for (int r = row2; r > row1; r--) {
                ans.push_back(matrix[r][col1]);
            }
            col1++;
            col2--;
            row1++;            
            row2--;
        }
        
        if (col1 == col2) {
            for (int r = row1; r <= row2; r++) {
                ans.push_back(matrix[r][col1]);
            }            
        } else if (row1 == row2) {
            for (int c = col1; c <= col2; c++) {
                ans.push_back(matrix[row1][c]);
            }
        }
        
        return ans;
    }
};