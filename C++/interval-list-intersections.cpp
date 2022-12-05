class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int n1 = firstList.size();
        int n2 = secondList.size();
        
        int i1 = 0, i2 = 0;
        
        while (i1 < n1 && i2 < n2) {
            vector<int>& a = firstList[i1];
            vector<int>& b = secondList[i2];
            
            int start = max(a[0], b[0]);
            int end = min(a[1], b[1]);
            
            if (start <= end) {
                ans.push_back({start, end});
            }
            
            if (a[1] < b[1]) {
                i1++;
            } else {
                i2++;
            }
        }
        
        return ans;
    }
};