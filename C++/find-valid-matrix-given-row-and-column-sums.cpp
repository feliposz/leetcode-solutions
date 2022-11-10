class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (rowSum[i] > 0 && colSum[j] > 0) {
                        int n = min(rowSum[i], colSum[j]);
                        matrix[i][j] += n;
                        rowSum[i] -= n;
                        colSum[j] -= n;
                        changed = true;
                    }
                }
            }
        }
        
        return matrix;
    }
};