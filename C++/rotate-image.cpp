class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz/2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][sz-j-1];
                matrix[i][sz-j-1] = t;
            }
        }
        
    }
};