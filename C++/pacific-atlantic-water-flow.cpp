class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        //print2D("Heights", heights);

        vector<vector<int>> rainPath(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            rainPath[i][0] |= 1;
            rainPath[i][n - 1] |= 2;
        }

        for (int j = 0; j < n; j++)
        {
            rainPath[0][j] |= 1;
            rainPath[m - 1][j] |= 2;
        }

        //print2D("Before", rainPath);
        
        bool changed = false;
        do
        {
            vector<vector<int>> prev = rainPath;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int h = heights[i][j];
                    if ((i > 0) && (h >= heights[i - 1][j]))
                    {
                        rainPath[i][j] |= rainPath[i - 1][j];
                    }
                    if ((i < m - 1) && (h >= heights[i + 1][j]))
                    {
                        rainPath[i][j] |= rainPath[i + 1][j];
                    }
                    if ((j > 0) && (h >= heights[i][j - 1]))
                    {
                        rainPath[i][j] |= rainPath[i][j - 1];
                    }
                    if ((j < n - 1) && (h >= heights[i][j + 1]))
                    {
                        rainPath[i][j] |= rainPath[i][j + 1];
                    }
                }
            }
            changed = rainPath != prev;
        } while (changed);

        //print2D("After", rainPath);

        vector<vector<int>> result;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rainPath[i][j] == 3)
                {
                    result.push_back({ i, j });
                }
            }
        }

        //print2D("Result", result);

        return result;
    }

    void print2D(string s, vector<vector<int>> &v)
    {
        int m = v.size();
        int n = v[0].size();
        cout << s << '\n';
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

};