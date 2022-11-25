class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        int n2 = n * n;

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        int id = 1;
        while (id <= n2)
        {
            for (int i = left; id <= n2 && i <= right; i++)
            {
                mat[top][i] = id++;
            }
            top++;
            for (int i = top; id <= n2 && i <= bottom; i++)
            {
                mat[i][right] = id++;
            }
            right--;
            for (int i = right; id <= n2 && i >= left; i--)
            {
                mat[bottom][i] = id++;
            }
            bottom--;
            for (int i = bottom; id <= n2 && i >= top; i--)
            {
                mat[i][left] = id++;
            }
            left++;
        }

        return mat;
    }
};