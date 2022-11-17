class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT32_MAX - 100000));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i-1][j]);
                    }
                    if (j > 0) {
                        dist[i][j] = min(dist[i][j], 1 + dist[i][j-1]);
                    }
                }
            }
        }

        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) {
                    dist[i][j] = min(dist[i][j], 1 + dist[i+1][j]);
                }
                if (j < n - 1) {
                    dist[i][j] = min(dist[i][j], 1 + dist[i][j+1]);
                }
            }
        }

        return dist;
    }
};