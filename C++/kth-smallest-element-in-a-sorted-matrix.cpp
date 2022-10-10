class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        
        for (vector<int> &row: matrix) {
            temp.insert(temp.end(), row.begin(), row.end());
        }
        
        sort(temp.begin(), temp.end());
        
        return temp[k-1];
    }
};