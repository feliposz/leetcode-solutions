class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int a : arr1) {
            bool ok = false;
            for (int b : arr2) {
                if (abs(a-b) > d) {
                    ok = true;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                count++;
            }
        }
        return count;
    }
};