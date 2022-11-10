class Solution
{
public:
    int regionsBySlashes(vector<string>& grid)
    {
        int id = 1;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> map(rows * 3, vector<int>(cols * 3, -1));

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '/')
                {
                    for (int i = 0; i < 3; i++)
                    {
                        map[r * 3 + i][c * 3 + 2 - i] = 0;
                    }
                }
                else if (grid[r][c] == '\\')
                {
                    for (int i = 0; i < 3; i++)
                    {
                        map[r * 3 + i][c * 3 + i] = 0;
                    }
                }
            }
        }

        //print2D("before", map);

        for (int r = 0; r < rows*3; r++)
        {
            for (int c = 0; c < cols*3; c++)
            {
                paint(map, r, c, id);
                id++;
            }
        }

        //print2D("after", map);

        set<int> unique;
        for (int r = 0; r < rows * 3; r++)
        {
            for (int c = 0; c < cols * 3; c++)
            {
                if (map[r][c] >= 1)
                {
                    unique.insert(map[r][c]);
                }
            }
        }

        return unique.size();
    }

    void paint(vector<vector<int>> &map, int r, int c, int id)
    {
        if (r >= 0 && c >= 0 && r < map.size() && c < map[0].size())
        {
            if (map[r][c] == -1)
            {
                map[r][c] = id;
                paint(map, r - 1, c, id);
                paint(map, r + 1, c, id);
                paint(map, r, c - 1, id);
                paint(map, r, c + 1, id);
            }
        }
    }
};