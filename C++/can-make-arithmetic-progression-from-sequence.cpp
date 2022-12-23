class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int delta = arr[1] - arr[0];

        int sz = arr.size();

        for (int i = 1; i < sz; i++) {
            if (arr[i] - arr[i-1] != delta) {
                return false;
            }
        }

        return true;
    }
};