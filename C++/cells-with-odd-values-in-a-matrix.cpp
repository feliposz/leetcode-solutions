class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m);
        for (int i = 0; i < m; i++) {
            mat[i].resize(n);
        }
        
        for (vector<int> &index: indices) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (index[0] == i) {
                        mat[i][j]++;
                    }
                    if (index[1] == j) {
                        mat[i][j]++;
                    }
                }
            }
        }
        
        int odds = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] % 2) {
                    odds++;
                }
            }
        }
        return odds;
    }
};