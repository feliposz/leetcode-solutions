class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0, end = m - 1;
        int row;
        while (start <= end) {
            row = (start + end) / 2;
            if (target < matrix[row][0]) {
                end = row - 1;
            } else if (target > matrix[row][n - 1]) {
                start = row + 1;
            } else {
                break;
            }
        }
        
        start = 0, end = n - 1;
        while (start <= end) {
            int col = (start + end) / 2;
            if (target < matrix[row][col]) {
                end = col - 1;
            } else if (target > matrix[row][col]) {
                start = col + 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};