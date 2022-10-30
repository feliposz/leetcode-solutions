class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int sz = arr.size();
        vector<int> result(sz);
        
        int max = -1;
        for (int i = sz - 1; i >= 0; i--) {
            result[i] = max;
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        
        return result;
    }
};