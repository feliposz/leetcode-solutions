class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool increasing = false;
        bool decreasing = false;
        int sz = arr.size();
        int i = 1;
        for (; i < sz; i++) {
            if (arr[i-1] < arr[i]) {
                increasing = true;
            } else if (arr[i-1] == arr[i]) {
                return false;
            } else {
                break;
            }
        }
        for (; i < sz; i++) {
            if (arr[i-1] > arr[i]) {
                decreasing = true;
            } else {
                decreasing = false;
                break;
            }
        }
        return increasing && decreasing;
    }
};