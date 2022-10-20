class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        if (rows == 0)
            return mat;
        
        int cols = mat[0].size();
        if (cols == 0)
            return mat;
        
        for (int row = 0; row < rows; row++) {
            bool done = false;
            while (!done) {
                done = true;
                for (int cell = 1; (row + cell < rows) && (cell < cols); cell++) {
                    if (mat[row+cell-1][cell-1] > mat[row+cell][cell]) {
                        swap(mat[row+cell-1][cell-1], mat[row+cell][cell]);
                        done = false;
                    }
                }
            }
        }
        
        for (int col = 1; col < cols; col++) {
            bool done = false;
            while (!done) {
                done = true;
                for (int cell = 1; (col + cell < cols) && (cell < rows); cell++) {
                    if (mat[cell-1][col+cell-1] > mat[cell][col+cell]) {
                        swap(mat[cell-1][col+cell-1], mat[cell][col+cell]);
                        done = false;
                    }
                }
            }
        }
        
        return mat;
    }
};