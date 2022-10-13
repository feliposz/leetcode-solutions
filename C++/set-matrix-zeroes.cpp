class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        
        if (matrix.size() == 0) {
            return;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeroes.push_back({i, j});
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (auto z: zeroes) {
                    if ((i == z.first) || (j == z.second)) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};