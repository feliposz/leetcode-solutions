class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i = 0; i < numRows; i++)
        {
            vector<int> current;
            for (int j = 0; j < i + 1; j++)
            {
                int val = 1;
                if ((i > 0) && (j > 0) && (j < i)) {
                    val = result[i-1][j-1] + result[i-1][j];
                }
                current.push_back(val);
            }
            result.push_back(current);
        }
        
        return result;
    }
};