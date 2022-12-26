class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int sz = mat.size();
        for (int i = 0; i < sz; i++) {
            int j = sz - i - 1;
            sum += mat[i][i];
            if (i != j) {
                sum += mat[i][j];
            }
        }
        return sum;
    }
};